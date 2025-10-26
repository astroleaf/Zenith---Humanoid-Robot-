#!/bin/bash
echo "Starting demo sequence..."

# Start data logging in background
python3 ../data_logs/log_data.py &

# Run perception pipeline demo
python3 ../perception/processing_scripts/capture_data.py

# Send sample commands to Arduino
python3 ../comms/examples/test_serial_link.py

echo "Demo sequence completed."
