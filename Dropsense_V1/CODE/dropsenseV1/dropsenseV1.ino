#include <Adafruit_MPU6050.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>

Adafruit_MPU6050 mpu;
Adafruit_Sensor *mpu_ax, *mpu_gr;

const int CS = 5;
File droplog; 

bool fall = false;
bool isStatic = true;   // ✅ renamed
bool impt = false;
String event = "stat";

void setup() {
  Serial.begin(115200);
  while (!Serial) delay(10);

  Serial.println("MPU6050 + SD test");

  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) delay(10);
  }

  Serial.println("MPU6050 Found!");

  mpu.setAccelerometerRange(MPU6050_RANGE_16_G);

  mpu_ax = mpu.getAccelerometerSensor();
  mpu_gr = mpu.getGyroSensor();

  mpu_ax->printSensorDetails();
  mpu_gr->printSensorDetails();

  if (!SD.begin(CS)) {
    Serial.println("SD init failed!");
    while (1);
  }

  Serial.println("SD ready!");

  droplog = SD.open("/droplog.csv", FILE_WRITE);

  if (droplog) {
    droplog.println("time,gForce,event");
    droplog.close();
  }
}

void loop() {
  sensors_event_t ax;
  sensors_event_t gr;

  mpu_ax->getEvent(&ax);
  mpu_gr->getEvent(&gr);

  float ax_val = ax.acceleration.x;
  float ay_val = ax.acceleration.y;
  float az_val = ax.acceleration.z;

  float gForce = sqrt(ax_val * ax_val + ay_val * ay_val + az_val * az_val) / 9.81;

  droplog = SD.open("/droplog.csv", FILE_APPEND);

  if (gForce < 1 && gForce > 0) {
    fall = true;
    isStatic = false;
    impt = false;
    event = "fall";
  }

  else if (gForce > 1 && gForce < 1.5) {
    fall = false;
    isStatic = true;
    impt = false;
    event = "stat";
  }

  else if (gForce > 2.5) {
    fall = false;
    isStatic = false;
    impt = true;
    event = "impt";
  }

  if (droplog) {
    droplog.print(millis());
    droplog.print(",");
    droplog.print(gForce);
    droplog.print(",");
    droplog.println(event);
    droplog.close();
  }

  Serial.print("G: ");
  Serial.print(gForce);
  Serial.print(" | ");
  Serial.println(event);

  delay(5);
}