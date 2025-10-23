---
title: src/AsyncState.cpp

---

# src/AsyncState.cpp






## Source code

```cpp
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
    long rem = (long)interval - (long)elapsed();
    return rem > 0 ? rem : 0;
}
```


-------------------------------

Updated on 2025-10-23 at 22:20:18 +0200
