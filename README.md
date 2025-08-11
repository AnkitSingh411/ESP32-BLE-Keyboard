# ESP32 BLE Keyboard with Advanced Payload Execution

This project transforms an ESP32 into a Bluetooth Low Energy (BLE) keyboard with advanced capabilities for penetration testing and red teaming.

## Features

- Emulates a BLE keyboard to send keystrokes to paired devices
- Automatically disables Windows Defender on the target machine
- Downloads and executes a reverse shell payload
- Provides remote shell access via Bluetooth connection

## Demo

Once paired with a target device, the ESP32 can execute commands to compromise the system and open a reverse shell for remote control.

## Requirements

- ESP32 development board
- Arduino IDE or PlatformIO with ESP32 support installed
- Bluetooth-enabled target device (Windows tested)

## Installation

1. Clone this repository:
   ```bash
   git clone https://github.com/AnkitSingh411/ESP32-BLE-Keyboard.git
