#ifndef _led_included_
#define _led_included_

#include "../../STM32Hardware/hardware.h"

class Led
{
private:
    DigitalPin _pin;
    int _toggleDelay;
    int _lastTime; // milli sec
    int _stat;

public:
    Led(DigitalPin pin, int toggleDelay);
    void On();
    void Off();
    void Toggle();
    ~Led();
};


Led::Led(DigitalPin pin, int toggleDelay)
{
    _pin = pin;
    _toggleDelay = toggleDelay;
    pinMode(_pin, OUTPUT);
    digitalWrite(_pin, LOW);
    this->_stat = LOW;
}

void Led::Off()
{
    digitalWrite(_pin, LOW);
    this->_stat = LOW;
}

void Led::On()
{
    digitalWrite(_pin, HIGH);
    this->_stat = HIGH;
}

void Led::Toggle()
{
    if ((millis() - this->_lastTime) < this->_toggleDelay)
        return;

    this->_lastTime = millis();
    if (this->_stat == LOW)
    {
        this->On();
    }
    else
    {
        this->Off();
    }
}

Led::~Led()
{
}
#endif