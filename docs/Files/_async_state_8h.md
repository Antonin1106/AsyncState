---
title: src/AsyncState.h
summary: Declaration of the AsyncState class for non-blocking timing control. 

---

# src/AsyncState.h

Declaration of the [AsyncState](Classes/class_async_state.md) class for non-blocking timing control.  [More...](#detailed-description)

## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[AsyncState](Classes/class_async_state.md)**  |

## Detailed Description

Declaration of the [AsyncState](Classes/class_async_state.md) class for non-blocking timing control. 

The **[AsyncState](Classes/class_async_state.md)** class provides a simple way to manage non-blocking timers based on the Arduino `millis()` function. It allows you to replace `delay()` calls with a more flexible, responsive timing mechanism.


# 
## 
### Example usage:



```cpp
#include <AsyncState.h>

AsyncState clock;

void loop() {
    if (clock.timePassed(300)) {
        Serial.println("300 ms passed!");
        clock.reset();
    }
}
```

This class does not use dynamic memory and can be used in performance-sensitive or memory-limited applications.

Antonin1106 

1.0.0 

2025-10-22 




## Source code

```cpp
#ifndef ASYNC_STATE_H
#define ASYNC_STATE_H

#include <Arduino.h>

class AsyncState
{
private:
    unsigned long startTime;

    bool paused;

    unsigned long pausedAt;

public:
    AsyncState();

    bool timePassed(unsigned long interval);

    void reset();

    void pause();

    void resume();

    unsigned long elapsed();

    long remaining(unsigned long interval);
};

#endif // ASYNC_STATE_H
```


-------------------------------

Updated on 2025-10-23 at 22:20:18 +0200
