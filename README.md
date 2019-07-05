This folder contains everything related to all academic students projects developed in 2016

1. Autonomous boat Degree Project
- This project does the live streaming from camera on boat to the android mobile.
- Android mobile creates wifi hotspot and Raspberry Pi on boat connect to it through external wifi module
- Android mobile acts as tcp server and boat as tcp client
- python code on Raspberry used for the controlling the boat motions and act as tcp client for data communication
- Additional arduino uno interface with Raspberry Pi through USB. Arduino has GPS, magnetic compass, accelerometer and Ph sensor iterface with it.
- Arduino keeps reading data from all the sensor and out it on serial port to Raspberry Pi.
- Raspberry pi sends data from arduino to android server.
- This folder contains everything regarding the project except the android software code.

2. Spy Robot
- This project does the live streaming from camera on spy robot to the android mobile.
- Android mobile creates wifi hotspot and Raspberry Pi on robot connect to it through external wifi module
- Android mobile acts as tcp server and robot as tcp client
- python code on Raspberry used for the controlling the robot motions and act as tcp client for data communication
- Additional gas sensor is interface with raspberry Pi and reads digital data if gas detects increase to threshold
- Raspberry pi sends data of gas sensor to android server.
- This folder contains everything regarding the project except the android software code.

3. RF id and zigbeed based Automatic car parking system
- This project mainly divided into three parts: 
	1. ir sensor and arduino due with Zigbee shield install at parking,
	2. Arduino uno with zigbee module, RF id reader, motor control and Graphic LCD to display empty space in parking.
	3. Database using visual studio for the dual time calculation and calculation of parking cost
- Each vehicle has passive rf id assigned. At entrance id read by rf reader and check if any free space available.
- If free space available then car is allowed to enter in the parking and allowed to park on free space shown on graphic LCD.
- Once car is parked on shown free space, ir sensor send all parked space data to the entrace system and update the free space details.
- Once car come to exit again the rf reader reads the id and calculate time and cost. Once payment received car allowed to exit and again
  free space in the parking get updated.
- This folder contains everything regarding the project.

4. American Standard Sign Language Representation Using Speech Recognition
- This project contains two parts
	1. Matlab speech recognition and GLCD display to show the hand gestures in the ameriacan standard lang for deaf and dumb people
	2. Arduino interface with GLCD receives data from serial and displays its corresponding hand gesture image on GLCD
- For speech recognition it uses Mel-frequency cestrum coefficien Algorithm.
- Once the pronounced character is recognized corresponding character is send on serial which then displaced on GLCD.
- Arduino Uno is interfaced with the GLCD to display the character.

5.Nrf and Bluetooth based Home Automation
- This Project contains 
	1.	HTTP Server tab, also act as hotspot for mobile and mobile access it through local webpage.
	2.  Tab communicates with master hardware over bluetooth for controlling appliance and sending alerts
	3.  Master hardware communicates with slave devices over nrf based propritory rf network.
- Slave device consists of Pir sensor and alaram device
- Master device consists of Relay based hardware for controlling of AC appliances
- This project only consists of codes for master and slave device (huter and PIR sensor). All devices has host mcu as P89v51 controller.
