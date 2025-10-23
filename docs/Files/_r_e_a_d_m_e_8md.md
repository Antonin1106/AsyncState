---
title: README.md

---

# README.md






## Source code

```markdown
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

# AsyncState

**AsyncState** is a lightweight **Arduino timing library** designed to simplify **non-blocking code** using the `millis()` function.  
It allows you to easily manage multiple independent timers without using `delay()` — ideal for responsive, event-driven Arduino projects.

---

## Main Features

- Create **multiple independent timers** using simple objects  
- Replace `delay()` with clean, non-blocking timing logic  
- Intuitive API: `timePassed()`, `reset()`, `pause()`, `resume()`  
- Suitable for:
  - LED animations  
  - Serial communication  
  - Sensor polling  
  - Motor or servo control  
  - Any time-based task without blocking the main loop  

---

## Technologies Used

- **Language:** Arduino C++  
- **Dependency:** None (pure C++)  
- **Development Tools:** Visual Studio Code / Arduino IDE  

---

## Installation

1. **Clone the repository or download the ZIP file:**
   ```bash
   git clone https://github.com/Antonin1106/AsyncState.git
   ```
2. **Copy the folder into your Arduino libraries directory:**
   ```bash
   Documents/Arduino/libraries/
   ```
3. **Restart the Arduino IDE**
4. **Include the library in your sketch**
   ```cpp
   #include <AsyncState.h>
   ```

---

## Quick Example

```cpp
#include <Arduino.h>
#include <AsyncState.h>

/* Create independent timers */
AsyncState clock;
AsyncState ledTimer;

void setup() {
  Serial.begin(115200);
  Serial.println("AsyncState Example Started!");
}

void loop() {
  /* Event every 300 ms */
  if (clock.timePassed(300)) {
    Serial.println("[Clock] 300 ms passed!");
    clock.reset();
  }

  /* Event every 1000 ms */
  if (ledTimer.timePassed(1000)) {
    Serial.println("[LED Timer] 1 second passed!");
    ledTimer.reset();
  }
}
```

---

## 📁 Project Structure

```bash
Documents\Arduino\libraries\AsyncState\
│
├── README.md
├── LICENSE
├── library.properties
├── keywords.txt
├── .gitignore
│
├── src\
│   ├── AsyncState.cpp
│   └── AsyncState.h
│
└── examples\
    ├── AsyncSerial\
    │   └── AsyncSerial.ino
    ├── AsyncLed\
    │   └── AsyncLed.ino
```

---

### Root Files
- **README.md** – Main documentation for the library  
- **LICENSE** – MIT license file describing usage terms  
- **library.properties** – Metadata for Arduino IDE recognition  
- **keywords.txt** – Keyword definitions for Arduino IDE syntax highlighting  
- **.gitignore** – Git configuration file for ignored content  

---

### `src/`
Contains the main source code of the library:
- **AsyncState.h / AsyncState.cpp** – Core class files defining the non-blocking timer system

---

### `examples/`
Includes ready-to-use Arduino sketches demonstrating how to use the library:
- **AsyncSerial.ino** – Example demonstrating multiple AsyncState timers in the Serial Monitor.
- **AsyncSerial.ino** – Example demonstrating AsyncState timer with led.

---

## Author

### [Antonin1106](https://github.com/Antonin1106) – Arduino & Web Developer
```


-------------------------------

Updated on 2025-10-23 at 22:20:18 +0200
