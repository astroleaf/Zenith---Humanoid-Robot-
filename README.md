include/# Humanoid Robot AI/ML Project


![Alt text](images/20241107-WA0007.jpg)

## Overview
This project integrates hardware control (Arduino) with AI/ML perception and cognition (SBC + Python) to build a fully functional humanoid robot. It supports motor control, sensor reading, AI-guided behavior, and safety monitoring.

## Directory Structure
- `firmware/` - Arduino firmware for motors and sensors
- `perception/` - AI perception pipelines and models
- `cognition/` - Decision-making and AI integration
- `comms/` - Communication bridge between SBC and Arduino
- `ml_models/` - Machine learning models and training scripts
- `data_logs/` - Performance and sensor data logs
- `scripts/` - Setup, calibration, and demo scripts
- `tests/` - Unit and integration tests
- `docs/` - Design docs and schematics

## Setup & Running
1. Run `scripts/setup_env.sh` to setup Python environment.
2. Connect hardware and upload firmware in `firmware/` via Arduino IDE or PlatformIO.
3. Start perception and communication modules on the SBC.
4. Use `scripts/run_demo.sh` to execute full demo pipeline.

## Hardware & Software Requirements
- Arduino Uno or compatible MCU
- Raspberry Pi or similar SBC
- Servo motors, ultrasonic sensors, IMU
- Webcam or CSI camera
- Python 3.8+, TensorFlow Lite, OpenCV

## Contribution
Please run tests in `tests/` before reports for stable operation.

## License
MIT License

## Contact
For queries and collaboration, contact [Your Email].

