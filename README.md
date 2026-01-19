# COSC111B_FINALPROJECT_MATIN-AO

# COSC 111 - Laboratory Activities Portfolio

This repository showcases all laboratory exercises and examination projects completed during COSC 111. Each activity focuses on essential concepts in embedded systems, sensor integration, serial communication, and programming fundamentals.

---

## 📁 Table of Contents
...

---

## 🔬 Laboratory Activities

### Laboratory 1: Basic LED Sequential Control
**Description**: A foundational Arduino program demonstrating sequential lighting control. Five LEDs connected to pins 12, 11, 10, 9, and 8 illuminate one at a time in a defined sequence.

**Features**:
- Activates LEDs sequentially in the forward direction.
- Implements a 1-second delay between each LED transition.
- Utilizes a simple looping structure for repeated control.

**Code Structure**:
- An array captures and organizes the pin assignments for the LEDs.
- `setup()`: Sets all the LED pins as outputs.
- `loop()`: Sequentially powers LEDs ON and OFF in a continuous loop.

---

### Laboratory 2: LED Control with PWM Brightness
**Description**: Expands LED control by introducing PWM (Pulse Width Modulation) for smooth brightness variation. Capable pins (such as 9, 10, and 11) are dimmed or brightened using fading effects.

**Features**:
- Smooth dimming and brightening of LEDs using PWM.
- Differentiates between standard and PWM-capable pins for brightness control.
- Includes forward and reverse animation of LED patterns.

**Code Structure**:
- Uses `analogWrite()` for brightness control on compatible pins.
- Defines conditional logic to apply either digital or analog control based on hardware capabilities.
- Implements loops for both sequential and reverse animations.

---

### Laboratory 3: Fire Detection System
**Description**: Combines sensor readings from a thermistor and a photoresistor to detect fire-like conditions. If threshold limits for both temperature and brightness are exceeded, an alert is triggered through LEDs or a buzzer.

**Features**:
- Reads temperature using a thermistor and the Steinhart-Hart equation.
- Monitors ambient brightness with a photoresistor.
- Activates alerts when sensor readings indicate possible fire conditions.

**Code Structure**:
- `readTemperature()` converts the analog signal from the thermistor into degrees Celsius.
- `readBrightness()` provides a scaled measurement of light intensity.
- The main loop monitors readings and triggers alerts when values exceed predefined limits.

---

### Laboratory 4: Light Detection Alert with Serial Control
**Description**: Monitors light intensity and activates a blinking alert if the brightness surpasses the threshold. Serial communication allows users to send commands (e.g., "stop") to deactivate the alert remotely.

**Features**:
- Real-time monitoring of light levels.
- Threshold-based activation and deactivation of alerts.
- User commands via serial input, such as stopping the blinking alert.

**Code Structure**:
- A dedicated function processes brightness readings and detects when they exceed the threshold.
- Serial communication is used to parse user commands and control the alert state.
- Dynamic management of the system’s alert activation.

---

### Laboratory 5: RGB LED Control via Serial Communication
**Description**: Implements a bi-directional communication system between Arduino and Python. By sending serial commands from Python, users can control RGB LEDs connected to the Arduino, with the option for special mixed-color effects.

**Features**:
- Serial-based command system for toggling individual or grouped LED colors.
- Custom control options, including "All LEDs ON" and specific mixes like "Violet" (Red + Blue).
- Modular design split between Arduino for LED actions and Python for user interaction.

**Code Structure**:
- Modular functions in the Arduino sketch process serial input commands.
- Python provides an interactive GUI-like menu for sending commands.
- Each serial input command maps directly to an LED action.

---

### Laboratory 6: Bi-directional Serial Communication
**Description**: Demonstrates two-way communication between Arduino and Python. Physical events such as button presses on the Arduino trigger actions on the Python side, which then sends responses back to control external hardware.

**Features**:
- Button presses on the Arduino are detected and transmitted as serial messages to Python.
- Python evaluates the input and sends corresponding commands to toggle LEDs.
- Output is dynamically updated in real time, enabling full interaction between both systems.

**Code Structure**:
- Modular header files define LED behavior and simplify toggling mechanisms.
- Python orchestrates communication, receiving data from Arduino and issuing control commands back.
- The Arduino loop continuously scans the state of buttons and reacts to serial commands.

---

### Laboratory 7: Web API Integration with FastAPI
**Description**: Integrates web-based functionality with embedded systems by using FastAPI for creating RESTful endpoints. These endpoints control various Arduino hardware components, such as LEDs.

**Features**:
- HTTP-based control of hardware, including toggling individual LEDs or activating all at once.
- FastAPI backend handles client requests and communicates with Arduino via serial.
- Real-time status updates, including hardware feedback.

**Code Structure**:
- API endpoints implement GET methods for various actions.
- Arduino listens for character-based serial commands and executes LED actions accordingly.
- Python manages both the API layer and the server-to-serial bridge.

---

## 📝 Examinations

### Lab Exam - Midterms: Light Intensity Monitoring System
**Description**: A dual-mode system for measuring and monitoring light intensity. Supports both automatic and manual threshold settings, with visual feedback provided by LEDs.

**Features**:
- Automatically adapts thresholds based on preset parameters (e.g., clear or cloudy conditions).
- Manual mode allows users to customize intensity thresholds using serial commands.
- LEDs indicate the current intensity range (low, medium, or high).

**Code Structure**:
- Functions are used to differentiate between auto and manual modes.
- Serial commands dynamically update threshold values, validated against predefined ranges.
- Intensity readings are scaled to percentages for easier interpretation.

---

### Lab Exam - Finals: Button Press Detection with API Integration
**Description**: Tracks button presses on an Arduino and communicates with an external API to log or trigger events based on button interactions.

**Features**:
- Edge detection ensures accurate tracking of momentary button presses.
- Sends HTTP requests to an external server, using endpoints to log button events or control connected devices.
- Structured serial communication between Arduino and Python ensures seamless data exchange.

**Code Structure**:
- Each button interaction is assigned a unique code sent over the serial interface.
- Python listens for serial input and issues HTTP API requests in response.
- Modular functions define button states and implement error handling for communication.