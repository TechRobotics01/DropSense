# DropSense
"what acctually happens when something drops"
dropsense answers that with data 

Dropsense is a wireless embedded system project which logs and transmits data in real time 
what type of data exactly?- it transmits the height from which it is dropped, the time period of the drop and the maximum Gforce which the device accelerated to during the impact .

Basically it consists of two parts the sender and the reciever 

# SENDER 
the sender consists of a custom made pcb which has a an esp32 s3 wroom 1 module an microsd card holder and a mpu6050(smd)
the sender will read the data and log it in sd card module and upomn impact that is g force greater than 5Gs then it will send info about the drop(height,time period etc) to the reciever btw this all is battery operated and it has a custom bms to power the pcb
<img width="929" height="658" alt="image" src="https://github.com/user-attachments/assets/0311351a-8092-4471-968e-bcc3a091356b" />
<img width="657" height="583" alt="image" src="https://github.com/user-attachments/assets/f962cbb1-7408-4d2d-a9bf-c70a38a921aa" />
<img width="722" height="621" alt="image" src="https://github.com/user-attachments/assets/b8094788-d81d-48e9-9bd5-b3ddf973b9cd" />
<img width="593" height="576" alt="image" src="https://github.com/user-attachments/assets/17191d2e-664a-4945-9712-77ee5a291479" />

This devise has hexagonal walls because they are better at abosrbing impacts!


# RECIEVER 
The reciever consists of an esp32 s3 wroom1 module and also an 1.8 inch tft display along with a custom made BMS for charging the battery which powers the pcb 
and the display shows all the info about the drop when it recieves the data fropm the sender 
<img width="928" height="657" alt="image" src="https://github.com/user-attachments/assets/f977aabb-da5c-4baa-a679-394620e35aa4" />
<img width="358" height="552" alt="image" src="https://github.com/user-attachments/assets/57fb9757-1a96-4aee-8d90-e64dfc590e5d" />
<img width="500" height="653" alt="image" src="https://github.com/user-attachments/assets/fbaf321e-8fbb-4377-8399-e875d1e401cd" />
<img width="762" height="576" alt="image" src="https://github.com/user-attachments/assets/c4e69588-bcef-446b-84ee-7ca4f80e0153" />
<img width="639" height="447" alt="image" src="https://github.com/user-attachments/assets/9d184bea-8cd3-432c-8dd0-3b61fc42d8c8" />


# IRL BUILD 
## SENDER
<img width="1990" height="1493" alt="IMG_20260905_121627" src="https://github.com/user-attachments/assets/b9a1a892-0d3a-4c18-8f32-881862a68b84" />
<img width="554" height="424" alt="image" src="https://github.com/user-attachments/assets/817cbc2f-0208-4c86-8fc0-ec9fcf95e6e2" />

## RECIEVER
<img width="2197" height="1648" alt="IMG_20260905_121718" src="https://github.com/user-attachments/assets/147a0f29-8e00-458d-9f33-1b34c0205ff8" />
<img width="798" height="545" alt="image" src="https://github.com/user-attachments/assets/8ac42d57-59ea-4da7-adf6-02251d590f5b" />


## ZINE PAGE
<img width="1398" height="2000" alt="DROPSENSE (2)" src="https://github.com/user-attachments/assets/6b9e89c0-a626-4e91-9b81-dc540c6af1cd" />

# Hardware
This device consists of 
1. MPU6050
2. Esp32-S3 module (not the development board)
3. sd card module 
4. custom BMS circuit
5. A small Li-Ion batter
6. 1.8 inch tft display 

All these parts will be on a custom made PCB whcih will be be enclosed inside a 3D printed case made out of TPU (you may also use PETG or CF-NYLON for added durability)

## THIS DEVICE HAS AN ERROR OF +-1CM FOR HEIGHT WHICH IS AM EXTREMELY LOW ERROR ##

# software
This was designed using the following softwares 

1. **Fusion360** for the 3d designing of the case
2. **KiCad** for the PCB design of this device

## CONTROL LOGIC
  1. in the prototyping stage
  2. The MPU6050 reads the values at a very high speed
  3. and then the valuse are logged into the sd card in a .csv file format
  4. then for prototyping the .csv file was read and analyzed
  5. figured out the threshold values such ad the gForce values which are required for automatic triggering and logging of data
  6. for eg when the device approached near 0 gForce vaklues the device is considered in a freefall and then the mpu605 starts to log the values in the sd card module and when the impact happend and the gForce stabelized at around 1Gfprce we can consider the device is stationary again and the Esp32 enters deep sleep mode again to save battery power
  7. the .csv file can then be used to plot graphs in different types of softwares for crash analysis
  8. also the crutial values such as drop height and maximum gForce of the crashb and the time time from falling to the crash is printed on the screen of the reciever 

## APPLICATIONS 
**this device can be used and applicated in places where gForce or acceleration and decelleration needs to be preciself analyzed**
1. drone crash analysis simply mount this device onto a drone and it will automaticaklly log the data when the drone crashes 
2. it can also be used in car crash analysis
3. this device acts as a black box for analysuis 


# credits (for R&D of this device)
google.com
https://randomnerdtutorials.com/arduino-mpu-6050-accelerometer-gyroscope/
Adafruit (use for taking out the values from mpu6050)
random nerd tutorials 
grabcad for the 3d step files of the tft and micro usb 




