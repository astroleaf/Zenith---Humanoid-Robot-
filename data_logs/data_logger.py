import csv
import time
import os

class DataLogger:
    def __init__(self, filename="data_log.csv"):
        self.filename = filename
        self.file = open(self.filename, mode='w', newline='')
        self.writer = csv.writer(self.file)
        self.writer.writerow(['timestamp', 'sensor_data', 'perception_output', 'command'])

    def log(self, sensor_data, perception_output, command):
        timestamp = time.time()
        self.writer.writerow([timestamp, sensor_data, perception_output, command])
        self.file.flush()

    def close(self):
        self.file.close()
