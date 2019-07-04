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