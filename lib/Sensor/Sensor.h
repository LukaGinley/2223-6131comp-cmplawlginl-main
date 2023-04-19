#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>
#include <DHT.h>
#include "RGB.h"
#include "Value.h"

class Sensor
{
public:
    // Constructor that takes the pin for the DHT sensor, an RGB object, and two Value objects for temperature and humidity ranges
    Sensor(int pin, RGB *rgb, Value *tempValue, Value *humValue);
    
    // Returns the current temperature
    float readTemperature();
    
    // Returns the current humidity
    float readHumidity();

    // Handles changes in temperature and humidity and updates the RGB LED
    void handleTemperatureAndHumidity();
    
    // Logs the current temperature and humidity readings to the Serial monitor
    void logSensorReadings();

private:
    // Private variables to hold the pin, DHT object, RGB object, and temperature and humidity ranges
    int _pin;
    DHT _dht;
    RGB *_rgb;
    Value *_tempValue;
    Value *_humValue;
    
    // Private variables to hold the current temperature and humidity readings, as well as information for flashing the RGB LED
    float _temperature;
    float _humidity;
    unsigned long _lastFlashMillis;
    bool _isRed;
    int _counter;
    
    // Private function to flash the RGB LED red and blue
    void _flashRedAndBlue();
};

#endif // SENSOR_H
