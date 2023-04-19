#ifndef VALUE_H
#define VALUE_H

class Value
{
public:
    // Constructor that takes a minimum and maximum value
    Value(float minValue, float maxValue);
    
    // Returns the minimum value
    float getMinValue();
    
    // Returns the maximum value
    float getMaxValue();

    // Sets the minimum value
    void setMinValue(float minValue);

    // Sets the minimum value
    void setMaxValue(float minValue);

private:
    // Private variables to hold the minimum and maximum values
    float _minValue;
    float _maxValue;
};

#endif