#ifndef RGB_H
#define RGB_H

#include <Arduino.h>

class RGB {
public:
    // Constructor
    RGB(int r_pin, int g_pin, int b_pin);

    // Set the color of the RGB LED
    void setColour(int r_value, int g_value, int b_value);

private:
    // Pin numbers for the RGB LED
    int r_pin;
    int g_pin;
    int b_pin;
    
    // Optional: boolean variable to indicate if the LED is currently flashing
    // bool isFlashing;
};

#endif

