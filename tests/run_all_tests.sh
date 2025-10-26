#!/bin/bash
echo "Running Unit Tests..."
arduino-cli compile --fqbn arduino:avr:uno ./tests/unit_tests/
# Add other test commands here
echo "Running Integration Tests..."
python3 ./tests/integration_tests/test_perception_pipeline.py
python3 ./tests/integration_tests/test_command_dispatcher.py
