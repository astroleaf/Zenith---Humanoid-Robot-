#!/bin/bash
echo "Setting up Python environment and dependencies..."
python3 -m venv venv
source venv/bin/activate
pip install --upgrade pip
pip install tensorflow opencv-python pyserial openai
echo "Environment setup complete."
