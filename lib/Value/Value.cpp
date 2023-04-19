#include "Value.h"

// Constructor that takes a minimum and maximum value
Value::Value(float minValue, float maxValue) : _minValue(minValue), _maxValue(maxValue)
{
    // Set the private variables to the values passed as arguments to the constructor
}

// Returns the minimum value
float Value::getMinValue()
{
    // Return the minimum value stored in the private variable
    return _minValue;
}

// Returns the maximum value
float Value::getMaxValue()
{
    // Return the maximum value stored in the private variable
    return _maxValue;
}
