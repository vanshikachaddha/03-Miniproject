# 2025 Fall ECE Senior Design Miniproject

[Project definition](./Project.md)

This project is a simple music system built on the Raspberry Pi Pico that demonstrates both pre-programmed playback and interactive control of musical notes.

### Ode to Joy Playback
At startup, the system automatically plays the classic melody Ode to Joy through a buzzer. The melody is defined as an array of notes (E4, F4, G4, etc.) and durations (quarter notes, half notes), which are looped through and played with appropriate timing.

### Interactive Note Control with Photosensor
After the song finishes, the system enters interactive mode. A photoresistor connected to an analog input pin detects light intensity. The sensor’s values are scaled and mapped to frequencies corresponding to musical notes (C4 to C5).

### Buzzer Output
A piezo buzzer is used as the sound output device. The tone() function generates square waves at the mapped frequencies, which correspond to notes in the Western musical scale.

In short, the system first plays a pre-composed melody and then switches to a light-controlled instrument mode where the user can explore sounds interactively.

## Design Approach

### System Architecture
The system is composed of three main components:
1. Input → Photosensor connected as a voltage divider to the Raspberry Pi Pico
2. Processing → Raspberry Pi Pico reads analog input, maps values to note frequencies, and controls playback logic.
3. Output → Piezo buzzer that produces audible notes.

## Comparison
1. Continuous vs. Discrete Notes:
- We initially considered mapping sensor values directly to continuous frequencies. However, this produced unstable and unpleasant tones. Switching to discrete notes (C4–C5) created a more musical and predictable output.

2. Input Method (Photosensor vs. Buttons):
- Buttons would have provided reliable, fixed notes, but the photosensor was chosen to make the system more interactive and dynamic. Light variation allows smoother user control and a more instrument-like experience.

3. Microcontroller Choice (Pico vs. Arduino):
- The Raspberry Pi Pico was selected for its affordability and available ADC pins. Arduino boards would have been equally capable but were less accessible for this build.

## Testing
To validate the mapping logic that converts sensor values into discrete notes, we wrote a simple unit test for the mapTest() function. This test simulates sensor inputs and checks whether the output matches the expected note frequencies.

We tested the system in two phases:

1. Predefined Song Playback:
- Verified that the buzzer successfully plays Ode to Joy at startup.
- Checked timing of notes (quarter vs half notes) to ensure the melody was recognizable.

2. Interactive Note Control
- Used different light conditions on the photosensor (covered, partial light, bright light).
- Confirmed that sensor values snapped correctly to discrete notes (C4 → C5).
- Observed Serial Monitor outputs to ensure scaling and mapping boundaries were consistent.

### Code Snippet

mapTest(700) → 262 (C4)   
mapTest(800) → 440 (A4)   
mapTest(900) → 523 (C5)   

### Expected Serial Output

Low passed

Middle passed

High passed

## Design Changes

### Discrete Note Mapping:
Instead of letting the photosensor produce continuous frequency values, we mapped sensor ranges to discrete musical notes (C4–C5). This ensured that the output always corresponded to recognizable tones rather than random pitches.

### Startup Melody (Ode to Joy):
We added a short playback of Ode to Joy at the beginning. This serves as a quick indicator that the system is running and the buzzer is functioning correctly before entering interactive mode.


## Demo




This project uses the Raspberry Pi Pico 2WH SC1634 (wireless, with header pins).

Each team must provide a micro-USB cable that connects to their laptop to plug into the Pi Pico.
The cord must have the data pins connected.
Splitter cords with multiple types of connectors fanning out may not have data pins connected.
Such micro-USB cords can be found locally at Microcenter, convenience stores, etc.
The student laptop is used to program the Pi Pico.
The laptop software to program and debug the Pi Pico works on macOS, Windows, and Linux.

This miniproject focuses on using
[MicroPython](./doc/micropython.md)
using
[Thonny IDE](./doc/thonny.md).
Other IDE can be used, including Visual Studio Code or
[rshell](./doc/rshell.md).

## Hardware

* Raspberry Pi Pico WH [SC1634](https://pip.raspberrypi.com/categories/1088-raspberry-pi-pico-2-w) (WiFi, Bluetooth, with header pins)
* Freenove Pico breakout board [FNK0081](https://store.freenove.com/products/fnk0081)
* Piezo Buzzer SameSky CPT-3095C-300
* 10k ohm resistor
* 2 [tactile switches](hhttps://www.mouser.com/ProductDetail/E-Switch/TL59NF160Q?qs=QtyuwXswaQgJqDRR55vEFA%3D%3D)

### Photoresistor details

The photoresistor uses the 10k ohm resistor as a voltage divider
[circuit](./doc/photoresistor.md).
The 10k ohm resistor connects to "3V3" and to ADC2.
The photoresistor connects to the ADC2 and to AGND.
Polarity is not important for this resistor and photoresistor.

The MicroPython
[machine.ADC](https://docs.micropython.org/en/latest/library/machine.ADC.html)
class is used to read the analog voltage from the photoresistor.
The `machine.ADC(id)` value corresponds to the "GP" pin number.
On the Pico W, GP28 is ADC2, accessed with `machine.ADC(28)`.

### Piezo buzzer details

PWM (Pulse Width Modulation) can be used to generate analog signals from digital outputs.
The Raspberry Pi Pico has eight PWM groups each with two PWM channels.
The [Pico WH pinout diagram](https://datasheets.raspberrypi.com/picow/PicoW-A4-Pinout.pdf)
shows that almost all Pico pins can be used for multiple distinct tasks as configured by MicroPython code or other software.
In this exercise, we will generate a PWM signal to drive a speaker.

GP16 is one of the pins that can be used to generate PWM signals.
Connect the speaker with the black wire (negative) to GND and the red wire (positive) to GP16.

In a more complete project, we would use additional resistors and capacitors with an amplifer to boost the sound output to a louder level with a bigger speaker.
The sound output is quiet but usable for this exercise.

Musical notes correspond to particular base frequencies and typically have rich harmonics in typical musical instruments.
An example soundboard showing note frequencies is [clickable](https://muted.io/note-frequencies/).
Over human history, the corresspondance of notes to frequencies has changed over time and location and musical cultures.
For the question below, feel free to use musical scale of your choice!


## Notes

Pico MicroPython time.sleep() doesn't error for negative values even though such are obviously incorrect--it is undefined for a system to sleep for negative time.
Duty cycle greater than 1 is undefined, so we clip the duty cycle to the range [0, 1].


## Reference

* [Pico 2WH pinout diagram](https://datasheets.raspberrypi.com/picow/pico-2-w-pinout.pdf) shows the connections to analog and digital IO.
* Getting Started with Pi Pico [book](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf)
