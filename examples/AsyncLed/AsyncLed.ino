/**
 * @file examples/AsyncLed/AsyncLed.ino
 * @brief Example demonstrating AsyncState timer with led.
 *
 * This example shows how to use a single AsyncState objects to handle
 * non-blocking timed events simultaneously.
 *
 * Board: Arduino AVR
 * Depends on: AsyncState
 *
 * @author Antonin1106
 * @copyright MIT License
 * @date 2025-10-23
 * @version 1.0.0
 */

#include <Arduino.h>
#include <AsyncState.h>

// Create the timer
AsyncState ledTimer;

// State of the led
bool ledState = false;

void setup()
{
    // Setup the output on the boards's builtin led
    pinMode(LED_BUILTIN, OUTPUT);
}

/**
 * @brief Example loop demonstrating how the timer works.
 */
void loop()
{
    // Change state every seconds
    if (ledTimer.timePassed(1000))
    {
        ledState = !ledState;
        digitalWrite(LED_BUILTIN, ledState);
        ledTimer.reset();
    }

    /* HERE YOU CAN HANDLE OTHER ACTIONS */
}
