import serial
import time

def calibrate_motors(port="/dev/ttyUSB0"):
    ser = serial.Serial(port, 115200)
    commands = ["MOVE_FORWARD 100", "STOP", "MOVE_BACKWARD 100", "STOP"]
    for cmd in commands:
        ser.write(f"{cmd}\n".encode())
        time.sleep(2)
    ser.close()

if __name__ == "__main__":
    calibrate_motors()
