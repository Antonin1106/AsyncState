/**
 * @file examples/AsyncSerial/AsyncSerial.ino
 * @brief Example demonstrating multiple AsyncState timers in the Serial Monitor.
 *
 * This example shows how to use several AsyncState objects to handle
 * different non-blocking timed events simultaneously. Each timer has
 * its own independent interval.
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

// Create multiple independent timers
AsyncState fastTimer;   // 200 ms
AsyncState mediumTimer; // 500 ms
AsyncState slowTimer;   // 1000 ms
AsyncState pauseDemo;   // used to show pause/resume feature

void setup()
{
    Serial.begin(115200);
    delay(1000);
    Serial.println();
    Serial.println(F("=== AsyncState Demonstration ==="));
    Serial.println(F("Multiple non-blocking timers running in parallel"));
    Serial.println(F("--------------------------------------------------"));
}

/**
 * @brief Example loop demonstrating how each timer works independently.
 */
void loop()
{
    // Event every 200 ms
    if (fastTimer.timePassed(200))
    {
        Serial.println(F("[FAST] Triggered every 200 ms"));
        fastTimer.reset();
    }

    // Event every 500 ms
    if (mediumTimer.timePassed(500))
    {
        Serial.println(F("[MEDIUM] Triggered every 500 ms"));
        mediumTimer.reset();
    }

    // Event every 1000 ms
    if (slowTimer.timePassed(1000))
    {
        Serial.println(F("[SLOW] Triggered every 1 second"));
        slowTimer.reset();
    }

    // Demonstrate pause/resume after 5 seconds
    if (pauseDemo.timePassed(5000))
    {
        static bool isPaused = false;

        if (!isPaused)
        {
            Serial.println(F("[PAUSE DEMO] Pausing all timers for 3 seconds..."));
            fastTimer.pause();
            mediumTimer.pause();
            slowTimer.pause();
            delay(3000); // only for demonstration purpose
            Serial.println(F("[PAUSE DEMO] Resuming timers!"));
            fastTimer.resume();
            mediumTimer.resume();
            slowTimer.resume();
        }

        isPaused = !isPaused;
        pauseDemo.reset();
    }
}
