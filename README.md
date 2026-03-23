# DropSense
I am creating an engineering learning and testing device which will calculate and log acceleration and gyroscopic values.\
these values can be later used to plot graphs and analysis

# Hardware
This device consists of 
1. MPU6050
2. Esp32-S3 module (not the development board)
3. sd card module 
4. BMS module
5. A small Li-Ion batter

All these parts will be on a custom made PCB whcih will be be enclosed inside a 3D printed case made out of PLA (you may also use PETG or CF-NYLON for added durability)

# software
This was designed using the following softwares 

1. **Fusion360** for the 3d designing of the case
2. **KiCad** for the PCB design of this device

## CONTROL LOGIC
***FOR V1***
  1. This is the prototyping stage
  2. The MPU6050 reads the values at a very high speed
  3. I simply read and analyzied the values to find the freefall and drop threshold for the V2


# credits (for R&D of this device)
google.com
https://randomnerdtutorials.com/arduino-mpu-6050-accelerometer-gyroscope/
Adafruit (use for taking out the values from mpu6050)



