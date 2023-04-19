# 2223-6131comp-cmplawlginl-main
Embedded System Home Environment Monitoring System

This is a prototype for an embedded system that monitors the ambient temperature and humidity in a home environment. The system is designed to detect and notify the user of any temperature or humidity issues that fall outside of pre-set ranges.

Features

- Ambient Temperature Monitoring
- Ambient Humidity Monitoring
- User-Set Minimum and Maximum Temperature and Humidity Values
- Status LED Notifications
- Temperature outside set range: RED light
- Humidity outside set range: BLUE light
- Both outside set range: FLASHING RED/BLUE light @ 2Hz
- Within set range: GREEN light
- User Input Capability
- LCD Display of Data Values
- WiFi Connectivity
- Remote Monitoring via Server Transmission
- Simple PHP Server Endpoint

Installation

To use this system, you will need to follow these steps:

Usage

Once the system is installed and connected, it will monitor the ambient temperature and humidity in the environment. If the temperature or humidity falls outside of the pre-set ranges, the system will notify the user via the status LED.

To view more detailed information about the temperature and humidity levels, the user can access the serial monitor. The user can also adjust the pre-set ranges for the temperature and humidity values.

The system can also transmit status updates to a remote server via WiFi. This allows for remote monitoring of the system and provides an additional layer of security for the home environment.

Components

The following components are used in this project:

- DHT22 temperature and humidity sensor
- RGB LED
- 220 Ohm resistor
- Microcontroller (ESP32)
- Breadboard
- Jumper wires
- Rotary switch encoder

Libraries

The following libraries are used in this project:

- Arduino.h: The core library for Arduino programming.
- Sensor.h: An external library used for the sensor module of the system.
- RGB.h: An external library used for controlling the RGB LED in the system.
- Value.h: An external library used for managing the minimum and maximum values for the temperature and humidity.
- Rotary.h: An external library used for reading rotary encoders, which can be used for user input in the system.
