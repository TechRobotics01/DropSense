
#include <Adafruit_MPU6050.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;
Adafruit_Sensor *mpu_accel, *mpu_gyro;
void setup() {

  Serial.begin(115200);
  while (!Serial)
    delay(10); 

  Serial.println("Adafruit MPU6050 test!");

  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!");
   
  mpu.setAccelerometerRange(MPU6050_RANGE_16_G);

  mpu_accel = mpu.getAccelerometerSensor();
  mpu_accel->printSensorDetails();

  mpu_gyro = mpu.getGyroSensor();
  mpu_gyro->printSensorDetails();

}

void loop() {
  sensors_event_t accel;
  sensors_event_t gyro;

  mpu_accel->getEvent(&accel);  
  mpu_gyro->getEvent(&gyro);

  Serial.print(accel.acceleration.x);
  Serial.print(","); Serial.print(accel.acceleration.y);
  Serial.print(","); Serial.print(accel.acceleration.z);
  Serial.print(",");

  Serial.print(gyro.gyro.x);
  Serial.print(","); Serial.print(gyro.gyro.y);
  Serial.print(","); Serial.print(gyro.gyro.z);
  Serial.println();
  
 delay(10);
}
