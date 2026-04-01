# DropSense
"what acctually happens when something drops"
dropsense answers that with data 

Dropsense is a wireless embedded system project which logs and transmits data in real time 
what type of data exactly?- it transmits the height from which it is dropped, the time period of the drop and the maximum Gforce which the device accelerated to during the impact .

Basically it consists of two parts the sender and the reciever 

# SENDER 
the sender consists of a custom made pcb which has a an esp32 s3 wroom 1 module an microsd card holder and a mpu6050(smd)
the sender will read the data and log it in sd card module and upomn impact that is g force greater than 5Gs then it will send info about the drop(height,time period etc) to the reciever btw this all is battery operated and it has a custom bms to power the pcb
<img width="687" height="754" alt="image" src="https://github.com/user-attachments/assets/c5ac8032-64be-4ba0-a0b9-5dbe4b12f088" />
<img width="786" height="695" alt="image" src="https://github.com/user-attachments/assets/58baf3d2-d3d3-48c9-804d-1076e52c4ed7" />
<img width="1101" height="677" alt="image" src="https://github.com/user-attachments/assets/497ca33e-e46a-4cf0-879f-f6f588b93035" />
<img width="1139" height="674" alt="image" src="https://github.com/user-attachments/assets/593e6f92-7913-440e-a417-61c0eb369822" />
This devise has hexagonal walls because they are better at abosrbing impacts!


# RECIEVER 
The reciever consists of an esp32 s3 wroom1 module and also an 1.8 inch tft display along with a custom made BMS for charging the battery which powers the pcb 
and the display shows all the info about the drop when it recieves the data fropm the sender 
<img width="641" height="703" alt="image" src="https://github.com/user-attachments/assets/95ad7505-4579-4d2d-9c2c-ab9d5841f978" />
<img width="557" height="696" alt="image" src="https://github.com/user-attachments/assets/b01d8796-d737-4b5b-81c0-f066a6e247b2" />
<img width="1167" height="637" alt="image" src="https://github.com/user-attachments/assets/578705b5-3e22-4886-8b45-ae9020cdbfc3" />
<img width="795" height="540" alt="image" src="https://github.com/user-attachments/assets/03c8cb1f-d1ef-437b-b207-1f0e0116e721" />



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




