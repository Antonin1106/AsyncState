# AsyncState

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT) ![Last commit](https://img.shields.io/github/last-commit/Antonin1106/AsyncState) ![Stars](https://img.shields.io/github/stars/Antonin1106/AsyncState)

**AsyncState** is a lightweight **Arduino timing library** designed to simplify **non-blocking code** using the `millis()` function.  
It allows you to easily manage multiple independent timers without using `delay()`, ideal for responsive, event-driven Arduino projects.


**This software is provided under the MIT License and is supplied "as is", without any warranty. Use it at your own risk.**


---
## Table of Contents
- [AsyncState](#asyncstate)
  - [Table of Contents](#table-of-contents)
  - [Main Features](#main-features)
  - [Technologies Used](#technologies-used)
  - [Installation](#installation)
  - [Quick Example](#quick-example)
  - [Memory usage](#memory-usage)
  - [Project Structure](#project-structure)
    - [Root Files](#root-files)
    - [`docs/`](#docs)
    - [`examples/`](#examples)
    - [`src/`](#src)


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

## Memory usage

`AsyncState` is designed to have a minimal memory footprint.

On most Arduino-compatible platforms (AVR, SAMD, ESP8266, ESP32), `sizeof(AsyncState)` is **9 bytes** or **12 bytes** due to structure alignment.

The member functions are stored only once in program memory (Flash) and are **not duplicated** for each instance. Creating additional `AsyncState` objects only increases RAM usage by the size of the instance itself.

> *Actual size may vary depending on the target architecture and compiler alignment rules.*

---

## Project Structure

```bash
Documents\Arduino\libraries\AsyncState\
│
├── .gitignore
├── keywords.txt
├── library.json
├── library.properties
├── LICENSE
├── README.md
│
├── docs\
│   ├── AsyncState.md
│   └── Doxyfile
│
├── examples\
│    ├── AsyncSerial\
│    │   └── AsyncSerial.ino
│    └── AsyncLed\
│        └── AsyncLed.ino
│
└── src\
    ├── AsyncState.cpp
    └── AsyncState.h
```

---

### Root Files
- **[.gitignore](.gitignore)** - Git configuration file for ignored content.
- **[keywords.txt](keywords.txt)** - Keyword definitions for Arduino IDE syntax.
- **[library.json](library.json)** - Metadata for PlatformIO recognition.
- **[library.properties](library.properties)** - Metadata for Arduino IDE recognition.
- **[LICENSE](LICENSE)** - License file describing usage terms.
- **[README.md](README.md)** - Main documentation for the library.

---

### [`docs/`](docs/)

Contains the **auto-generated documentation** produced by [Doxygen](https://www.doxygen.nl/)  
and converted to **Markdown** using [moxygen](https://github.com/sourcey/moxygen).

- **[AsyncState.md](docs/AsyncState.md)** - Auto-generated markdown output.
- **[Doxyfile](docs/Doxyfile)** - Configuration file for Doxygen.

This folder provides browsable documentation directly within GitHub or static site tools.

> Note: The content in this folder is **automatically generated** -
> **do not edit manually**, as it will be overwritten each time Doxygen or moxygen is run.
>
> To regenerate the documentation:
> ```bash
> doxygen docs/Doxyfile
> moxygen --output docs/AsyncState.md docs/xml 
> ```

---

### `examples/`
Includes ready-to-use Arduino sketches demonstrating how to use the library:
- **[AsyncSerial.ino](examples/AsyncSerial/AsyncSerial.ino)** – Example demonstrating multiple AsyncState timers in the Serial Monitor.
- **[AsyncLed.ino](examples/AsyncLed/AsyncLed.ino)** – Example demonstrating AsyncState timer with led.

---

### `src/`
Contains the main source code of the library:
- **[AsyncState.h](src/AsyncState.h) / [AsyncState.cpp](src/AsyncState.cpp)** – Core class files defining the non-blocking timer system.