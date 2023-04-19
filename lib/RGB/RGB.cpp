#include "RGB.h"

// Constructor: initializes RGB pins as OUTPUT
RGB::RGB(int r_pin, int g_pin, int b_pin)
{
    r_pin = r_pin;
    g_pin = g_pin;
    b_pin = b_pin;

    pinMode(r_pin, OUTPUT);    // Set red pin as OUTPUT
    pinMode(g_pin, OUTPUT);    // Set green pin as OUTPUT
    pinMode(b_pin, OUTPUT);    // Set blue pin as OUTPUT
}

// Function: sets RGB color
void RGB::setColour(int r_value, int g_value, int b_value)
{
    analogWrite(r_pin, r_value);  // Write red value to red pin
    analogWrite(g_pin, g_value);  // Write green value to green pin
    analogWrite(b_pin, b_value);  // Write blue value to blue pin
}