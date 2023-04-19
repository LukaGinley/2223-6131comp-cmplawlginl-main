#include <Arduino.h>
#include <Sensor.h>
#include <RGB.h>
#include <Value.h>
#include <Rotary.h>

// Define the pins used by the system
// RGB LED pins
#define R_LED 4
#define G_LED 16
#define B_LED 17
// DHT11 temperature and humidity sensor pin
#define DHTPIN 15
#define DHTTYPE DHT11
// Rotary encoder pins
#define ROTARY_PIN_A 27
#define ROTARY_PIN_B 26
#define ROTARY_PIN_BUTTON 21
#define ROTARY_PIN_SWITCH 33

// Create an instance of the DHT11 sensor and RGB LED
DHT dht(DHTPIN, DHTTYPE);
Sensor sensor(DHTPIN, new RGB(R_LED, G_LED, B_LED), new Value(20.0, 30.0f), new Value(50, 80.0f));

void setup() {
  // Initialize the serial port
  Serial.begin(115200);

  // Print a message to the console indicating that the DHT sensor is being calibrated
  Serial.println("Calibrating DHT Sensor...");

  // Wait for 2 seconds before starting to read the sensor
  delay(2000);

  // Begin reading the DHT11 sensor
  dht.begin();
}

void loop() {
  // Feature B: Log the temperature and humidity every 5 seconds
  static unsigned long lastLogMillis = 0;
  unsigned long currentMillis = millis();

  if (currentMillis - lastLogMillis >= 5000) {
    // Update lastLogMillis
    lastLogMillis = currentMillis;

    // Log the temperature and humidity readings from the sensor
    sensor.logSensorReadings();
  }

  // Feature A: Handle temperature and humidity changes
  sensor.handleTemperatureAndHumidity();
}