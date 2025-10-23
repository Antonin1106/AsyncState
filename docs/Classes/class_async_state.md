---
title: AsyncState

---

# AsyncState






`#include <AsyncState.h>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[AsyncState](Classes/class_async_state.md#function-asyncstate)**()<br>Constructs a new [AsyncState](Classes/class_async_state.md) timer.  |
| bool | **[timePassed](Classes/class_async_state.md#function-timepassed)**(unsigned long interval)<br>Checks if the specified interval has passed since the last reset.  |
| void | **[reset](Classes/class_async_state.md#function-reset)**()<br>Resets the timer start time to the current value of `millis()`.  |
| void | **[pause](Classes/class_async_state.md#function-pause)**()<br>Pauses the timer.  |
| void | **[resume](Classes/class_async_state.md#function-resume)**()<br>Resumes a previously paused timer.  |
| unsigned long | **[elapsed](Classes/class_async_state.md#function-elapsed)**()<br>Returns the elapsed time since the timer started or was last reset.  |
| long | **[remaining](Classes/class_async_state.md#function-remaining)**(unsigned long interval)<br>Returns the remaining time before the specified interval completes.  |

## Public Functions Documentation

### function AsyncState

```cpp
AsyncState()
```

Constructs a new [AsyncState](Classes/class_async_state.md) timer. 

Initializes the timer as not paused and starts it immediately. 


### function timePassed

```cpp
bool timePassed(
    unsigned long interval
)
```

Checks if the specified interval has passed since the last reset. 

**Parameters**: 

  * **interval** Duration in milliseconds to check. 


**Return**: `true` if the interval has passed, `false` otherwise.

**Note**: The timer continues running after the interval has passed. You can call `[reset()](Classes/class_async_state.md#function-reset)` to restart it manually. 

### function reset

```cpp
void reset()
```

Resets the timer start time to the current value of `millis()`. 

This is equivalent to restarting the timer. 


### function pause

```cpp
void pause()
```

Pauses the timer. 

The elapsed time is frozen until `[resume()](Classes/class_async_state.md#function-resume)` is called. Useful when you need to temporarily halt timing logic. 


### function resume

```cpp
void resume()
```

Resumes a previously paused timer. 

Restores the timer’s progression by compensating for the paused duration. 


### function elapsed

```cpp
unsigned long elapsed()
```

Returns the elapsed time since the timer started or was last reset. 

**Return**: The number of milliseconds elapsed. 

### function remaining

```cpp
long remaining(
    unsigned long interval
)
```

Returns the remaining time before the specified interval completes. 

**Parameters**: 

  * **interval** Duration in milliseconds. 


**Return**: A positive number if time remains, or a negative number if the interval has passed. 

-------------------------------

Updated on 2025-10-23 at 22:20:18 +0200