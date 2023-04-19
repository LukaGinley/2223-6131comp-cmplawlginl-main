#include "Sensor.h"
#include <DHT.h>

// Constructor: Initializes the Sensor object with the given parameters and sets initial values
Sensor::Sensor(int pin, RGB *rgb, Value *tempValue, Value *humValue)
    : _pin(pin),
      _dht(pin, DHT11),
      _rgb(rgb),
      _tempValue(tempValue),
      _humValue(humValue),
      _temperature(0),
      _humidity(0),
      _lastFlashMillis(0),
      _isRed(false)
{
    _dht.begin(); // Start DHT sensor
}

// Returns the last registered temperature
float Sensor::readTemperature()
{
    return _temperature;
}

// Returns the last registered humidity
float Sensor::readHumidity()
{
    return _humidity;
}

// Checks the temperature and humidity readings and changes the RGB LED accordingly
void Sensor::handleTemperatureAndHumidity()
{
    // Read temperature and humidity
    _temperature = _dht.readTemperature();
    _humidity = _dht.readHumidity();

    // Check if temperature and/or humidity readings are out of range
    boolean isTemperatureOutOfRange = _temperature < _tempValue->getMinValue() || _temperature > _tempValue->getMaxValue();
    boolean isHumidityOutOfRange = _humidity < _humValue->getMinValue() || _humidity > _humValue->getMaxValue();

    // Handle out of range readings
    if (isTemperatureOutOfRange && isHumidityOutOfRange)
    {
        // Flash the LED between red and blue
        unsigned long currentMillis = millis();
        if (currentMillis - _lastFlashMillis >= 500)
        {
            _lastFlashMillis = currentMillis;
            if (_isRed)
            {
                _rgb->setColour(0, 0, 255); // Blue
                _isRed = false;
            }
            else
            {
                _rgb->setColour(255, 0, 0); // Red
                _isRed = true;
            }
        }
    }
    else if (isTemperatureOutOfRange)
    {
        _rgb->setColour(255, 0, 0); // Red
    }
    else if (isHumidityOutOfRange)
    {
        _rgb->setColour(0, 0, 255); // Blue
    }
    else
    {
        // System OK, set LED to green
        _rgb->setColour(0, 255, 0); // Green
    }
}

// Logs the sensor readings and specified min/max values to the Serial Monitor
void Sensor::logSensorReadings()
{
    // Print current temperature and humidity readings
    Serial.print("REGISTERED Temperature: ");
    Serial.print(_temperature);
    Serial.print("C, REGISTERED Humidity: ");
    Serial.print(_humidity);
    Serial.println("% \n");

    // Check if temperature and/or humidity readings are out of range
    boolean isTemperatureOutOfRange = _temperature < _tempValue->getMinValue() || _temperature > _tempValue->getMaxValue();
    boolean isHumidityOutOfRange = _humidity < _humValue->getMinValue() || _humidity > _humValue->getMaxValue();

    // Print specified min/max values
    Serial.print("SPECIFIED Temp Min: ");
    Serial.println(_tempValue->getMinValue());
    Serial.print("SPECIFIED Temp Max: ");
    Serial.println(_tempValue->getMaxValue());
    Serial.print("SPECIFIED Hum Min: ");
    Serial.println(_humValue->getMinValue());
    Serial.print("SPECIFIED Hum Max: ");
    Serial.println(_humValue->getMaxValue());

    // Check if temperature and/or humidity is out of range and print appropriate message
    if (isTemperatureOutOfRange && isHumidityOutOfRange)
    {
        Serial.println("\nTEMPERATURE and HUMIDITY issue.\n");
    }
    else if (isTemperatureOutOfRange)
    {
        Serial.println("\nTEMPERATURE issue.\n");
    }
    else if (isHumidityOutOfRange)
    {
        Serial.println("\nHUMIDITY issue.\n");
    }
    else
    {
        Serial.println("\nSystem OK.\n");
    }
}