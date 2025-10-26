Humanoid Robot AI/ML Project

![WhatsApp Image 2025-10-27 at 00 18 13_5ef50361](https://github.com/user-attachments/assets/9a720a4e-9cc1-4e36-a292-9ce4ff601c9d)

![WhatsApp Image 2025-10-27 at 00 18 14_ed6219e1](https://github.com/user-attachments/assets/0ec3cd1a-af9b-4ef7-a64c-095bb585645b)

![WhatsApp Image 2025-10-27 at 00 18 14_d90d4b1d](https://github.com/user-attachments/assets/18a71bd8-8ff1-41b7-99e1-d192e46282ae)

![IMG-20241107-WA0007](https://github.com/user-attachments/assets/e60ebf81-c205-4f5a-98f1-e8d59d1137a4)

![IMG-20241107-WA0011](https://github.com/user-attachments/assets/dafb85ea-caed-4061-89c6-f2328393d957)

![IMG-20241107-WA0009](https://github.com/user-attachments/assets/da502000-9306-47ab-9958-d788b8d97fd6)

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



