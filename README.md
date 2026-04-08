#  3-Floor Digital Elevator Control System using Arduino

This project is a simple simulation of a *3-floor elevator system* built using Arduino Uno.  
It demonstrates how a real elevator works with floor selection, display indication, LED signaling, and buzzer alerts.

---

##  Features

- Floor selection using push buttons (0–3)
- 7-segment display shows current floor
- LEDs blink to simulate elevator movement
- When elevator reaches a floor:
  - LED + buzzer turn ON for 3 seconds
- Ground floor has special indication (10 blinks)
- Energy-efficient design:
  - LEDs automatically turn OFF after a few seconds

---

##  Real-World Application

This project simulates basic elevator logic used in buildings:
- Visual and audio feedback for users
- Efficient control system behavior
- Energy-saving concept by turning OFF indicators when not needed

---

##  Learning Outcomes

- Understanding of Arduino digital I/O
- Hardware + software integration
- Logic building for real-world systems
- Timing control using delays
- Basics of embedded systems design

---

##  Components Used

- Arduino Uno
- 7-Segment Display (Common Cathode)
- LEDs
- Push Buttons
- Buzzer
- Breadboard
- Jumper Wires
- 220Ω Resistors

---

##  Circuit Connections

### Buttons:
- One side → Arduino pin (A1, 9, 10, 11)
- Other side → GND
- Using INPUT_PULLUP

### LEDs:
- Arduino pin → Resistor → LED → GND

### Buzzer:
- Positive → A3  
- Negative → GND  

### 7-Segment Display:
- Common Cathode → GND  
- Segments (a–g) → Pins 2–8 via resistors  

---

##  Working

1. System starts at *Ground Floor (0)*
2. Press any floor button:
   - LED blinks (movement simulation)
3. Once elevator reaches the selected floor:
   - LED + buzzer turn ON for 3 seconds
4. Then everything turns OFF automatically

---

##  Code

Upload the provided Arduino .ino file to your board.

---

##  Future Improvements

- Add LCD display
- Add direction indicators (↑ ↓)
- Add voice announcement system
- Replace delay with non-blocking code (millis)

---

##  Author

Built as a learning project to understand embedded systems and real-world control logic.