#ifndef ASYNC_STATE_H
#define ASYNC_STATE_H

#include <Arduino.h>

/**
 * @file AsyncState.h
 * @brief Declaration of the AsyncState class for non-blocking timing control.
 *
 * The **AsyncState** class provides a simple way to manage non-blocking timers
 * based on the Arduino `millis()` function. It allows you to replace `delay()`
 * calls with a more flexible, responsive timing mechanism.
 *
 * ### Example usage:
 * @code
 * #include <AsyncState.h>
 *
 * AsyncState clock;
 *
 * void loop() {
 *     if (clock.timePassed(300)) {
 *         Serial.println("300 ms passed!");
 *         clock.reset();
 *     }
 * }
 * @endcode
 *
 * @author Antonin1106
 * @version 1.0.0
 * @date 2025-10-22
 */
class AsyncState
{
private:
    /**
     * @brief Stores the time (in milliseconds) when the timer was last started or reset.
     */
    unsigned long startTime;

    /**
     * @brief Indicates whether the timer is currently paused.
     */
    bool paused;

    /**
     * @brief Stores the timestamp when the timer was paused.
     */
    unsigned long pausedAt;

public:
    /**
     * @brief Constructs a new AsyncState timer.
     *
     * Initializes the timer as not paused and starts it immediately.
     */
    AsyncState();

    /**
     * @brief Checks if the specified interval has passed since the last reset.
     *
     * @param interval Duration in milliseconds to check.
     * @return `true` if the interval has passed, `false` otherwise.
     *
     * @note The timer continues running after the interval has passed.
     *       You can call `reset()` to restart it manually.
     */
    bool timePassed(unsigned long interval);

    /**
     * @brief Resets the timer start time to the current value of `millis()`.
     *
     * This is equivalent to restarting the timer.
     */
    void reset();

    /**
     * @brief Pauses the timer.
     *
     * The elapsed time is frozen until `resume()` is called.
     * Useful when you need to temporarily halt timing logic.
     */
    void pause();

    /**
     * @brief Resumes a previously paused timer.
     *
     * Restores the timer’s progression by compensating for the paused duration.
     */
    void resume();

    /**
     * @brief Returns the elapsed time since the timer started or was last reset.
     *
     * @return The number of milliseconds elapsed.
     */
    unsigned long elapsed();

    /**
     * @brief Returns the remaining time before the specified interval completes.
     *
     * @param interval Duration in milliseconds.
     * @return A positive number if time remains, or a negative number if the interval has passed.
     */
    long remaining(unsigned long interval);
};

#endif // ASYNC_STATE_H
