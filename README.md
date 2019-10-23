# Arduino-Hydraulic-Controller
Digital Controller - PI, to operate hydraulic system applying microcontroller - Arduino UNO 

With the evolution of embedded technology, programmed microcontrollers are likely to be implemented to operate automated hydraulic systems, controlling motor pumps according to the needs imposed by process variables. This work focuses on verify the automatic drive viability of hydraulic pumps, using microcontrollers, according to the state of tank levels detected by sensors, as well as monitoring and accomplishing data acquisition inherent in the system. To perform field tests, a prototype was built to transfer water between tanks, in order to analyze the reliability and accuracy of the components, as well as the values obtained. 

![3)Desenho_esquemático(autor)_arduino_PI](https://user-images.githubusercontent.com/43359860/67165702-d22ab380-f35e-11e9-96d8-fad5b8a123f9.jpg)

In this project (seted up in sketch above), system automation is based on the PI (Proportional Integral) control action, that control armature voltage as tank level varies. The level is monitored by the HC-SR03 ultrasonic sensor, installed on the tank top. The measurement obtained is the MCU reference for implementing the PWM output voltage setpoint. Thus, the pump water flow can be adjusted according to the tank level. In this case, the level varies according to the opening or closing of the register installed at the bottom of the the tank, simulating the water system demand/consumption.

The control action of this system is represented in the block diagram below.
![diagrama de blocos_controlador-PI(2)](https://user-images.githubusercontent.com/43359860/67256359-0389a900-f45d-11e9-9d95-df39892849c5.JPG)

PI controller data is monitored by Matlab via serial communication. To enable the USB / TTL interface, the FT232R converter is used, so the data obtained is viewed on the screen and the graphs of the variables (level, set point, error, A / D sensor) are plotted in real time with program routine (PI_ArduinoSerial.m).

(Text reference: Hydraulic Automation to Drive Motor Pumps Using Microcontrollers)
