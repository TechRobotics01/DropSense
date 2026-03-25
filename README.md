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
***WORK DONE  FOR V1***
  1. This is the prototyping stage
  2. The MPU6050 reads the values at a very high speed
  3. and then the valuse are logged into the sd card in a .csv file format
  4. then for prototyping the .csv file was read and analyzed
  5. figured out the threshold values such ad the gForce values which are required for automatic triggering and logging of data
  6. for eg when the device approached near 0 gForce vaklues the device is considered in a freefall and then the mpu605 starts to log the values in the sd card module and when the impact happend and the gForce stabelized at around 1Gfprce we can consider the device is stationary again and the Esp32 enters deep sleep mode again to save battery power
  7. the .csv file can then be used to plot graphs in different types of softwares for crash analysis

## APPLICATIONS 
**this device can be used and applicated in places where gForce or acceleration and decelleration needs to be preciself analyzed**
1. drone crash analysis simply mount this device onto a drone and it will automaticaklly log the data when the drone crashes 
2. it can also be used in car crash analysis
3. this device acts as a black box for analysuis 


# credits (for R&D of this device)
google.com
https://randomnerdtutorials.com/arduino-mpu-6050-accelerometer-gyroscope/
Adafruit (use for taking out the values from mpu6050)



