#include <Adafruit_MPU6050.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>

Adafruit_MPU6050 mpu;
Adafruit_Sensor *mpu_ax, *mpu_gr;

const int CS = 5;
File droplog; 

float fallTime = 0;  
float height = 0;
float maxG = 0;

bool fall = false;
bool isStatic = true;
bool impt = false;

String event = "stat";

float gForce = 0;

unsigned long fallstart = 0;
unsigned long impact = 0;

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

  readmpu();
  status();
  hndlimpt();
  logdata();

  delay(1);
}

void readmpu(){
  sensors_event_t ax;
  sensors_event_t gr;

  mpu_ax->getEvent(&ax);
  mpu_gr->getEvent(&gr);

  float ax_val = ax.acceleration.x;
  float ay_val = ax.acceleration.y;
  float az_val = ax.acceleration.z;

  float rawG = sqrt(ax_val * ax_val + ay_val * ay_val + az_val * az_val) / 9.81;

  gForce = rawG;

  if(rawG > maxG){
    maxG = rawG;
  }
}

void status(){
  if (gForce < 0.30 && gForce > 0 && !fall) {
    fall = true;
    isStatic = false;
    impt = false;
    event = "fall";
  }

  else if (gForce > 0.85 && gForce < 1.5) {
    fall = false;
    isStatic = true;
    impt = false;
    event = "stat";
  }

  else if (gForce > 5 && fall) {  
    impt = true;
    event = "impt";
  }
}

void hndlimpt(){
  static bool fallstarted = false;
  static bool impactdetected = false;

  if (fall && !fallstarted){
    fallstarted = true;
    fallstart = millis();
    Serial.println("FALLING...");
  }

  else if (impt && !impactdetected){
    impactdetected = true;
    impact = millis();
    Serial.println("IMPACT DETECTED!!!");

    fallTime = (impact - fallstart) / 1000.0;
    height = 0.5 * 9.8 * fallTime * fallTime;
    height *= 1.3;   

    Serial.print("TIME PERIOD = ");
    Serial.println(fallTime);

    Serial.print("HEIGHT = ");
    Serial.println(height);

    Serial.print("PEAK GFORCE = ");   
    Serial.println(maxG);
  }

  if (impt){
    delay(2000);

    maxG = 0;   

    fall = false;
    impt = false;
    event = "stat";

    fallstarted = false;
    impactdetected = false;
  }
}

void logdata(){ 
  droplog = SD.open("/droplog.csv", FILE_APPEND); 
 
  if (droplog) {
    droplog.print(millis());
    droplog.print(",");
    droplog.print(gForce);
    droplog.print(",");
    droplog.println(event);
    droplog.close();
  }
}

void smoothGForce() {
  static float prevG = 0;   
  float alpha = 0.7;

  gForce = alpha * prevG + (1 - alpha) * gForce;
  prevG = gForce;
}