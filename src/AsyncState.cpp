#include "AsyncState.h"

AsyncState::AsyncState()
{
    startTime = millis();
    paused = false;
    pausedAt = 0;
}

bool AsyncState::timePassed(unsigned long interval)
{
    if (paused)
        return false;
    return (millis() - startTime) >= interval;
}

void AsyncState::reset()
{
    startTime = millis();
    paused = false;
    pausedAt = 0;
}

void AsyncState::pause()
{
    if (!paused)
    {
        paused = true;
        pausedAt = millis();
    }
}

void AsyncState::resume()
{
    if (paused)
    {
        unsigned long pausedDuration = millis() - pausedAt;
        startTime += pausedDuration;
        paused = false;
        pausedAt = 0;
    }
}

unsigned long AsyncState::elapsed()
{
    if (paused)
        return pausedAt - startTime;
    return millis() - startTime;
}

long AsyncState::remaining(unsigned long interval)
{
   return (long)interval - (long)elapsed();
}
