# Automotive Battery Diagnostics Monitor (Simulation)

A simulated vehicle battery diagnostics system built on the ATmega328P microcontroller that monitors real-time voltage profiles across a 0–16V range.

## Overview

Automotive charging systems operate within strict voltage windows. This project replicates that diagnostic logic in firmware — classifying system health in real time using a Finite State Machine, with all tasks running on a non-blocking time-slice architecture.

## FSM State Diagram

| Voltage Range     | State              | LED |
|-------------------|--------------------|-----|
| < 13.5V           | ENGINE_OFF         | OFF |
| 13.5V – 15.0V     | NORMAL_CHARGING    | OFF |
| > 15.0V           | OVERVOLTAGE_FAULT  | ON  |

## Features

- ATmega328P microcontroller (Arduino Uno)
- Real-time ADC sampling mapped to 0–16V voltage range
- Deterministic FSM with 3 operating states
- Non-blocking firmware — all tasks (read, FSM update, LED, serial log) run on a 200ms time slice using `millis()`
- Serial telemetry output at 115200 baud

## Simulation

Built and tested on Wokwi. A potentiometer on A0 simulates battery voltage from 0–16V.

🔗 [Open in Wokwi](https://wokwi.com/projects/465072315428355073)

## Serial Output (Sample)
AUTOMOTIVE BATTERY MONITOR SYSTEM INITIALIZED.
Battery Voltage V : 12.34 , System State ID : 0
Battery Voltage V : 14.10 , System State ID : 1
Battery Voltage V : 15.67 , System State ID : 2

## Tech Stack

- Language: Embedded C (Arduino framework)
- MCU: ATmega328P
- IDE: Arduino IDE
- Simulation: Wokwi

## Future Improvements

- Add GSM module for SMS fault alerts
- Log data to SD card for post-drive analysis
- Port to bare-metal AVR (no Arduino framework)
- Expand FSM with Undervoltage and Battery Dead states
