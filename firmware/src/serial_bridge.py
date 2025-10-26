import serial
import time

class SerialBridge:
    def __init__(self, port='/dev/ttyUSB0', baudrate=115200, timeout=1):
        self.ser = serial.Serial(port, baudrate, timeout=timeout)
        time.sleep(2)  # wait for connection

    def send_command(self, command):
        cmd_str = command + '\n'
        self.ser.write(cmd_str.encode('utf-8'))
        print(f"Sent command: {command}")

    def read_response(self):
        if self.ser.in_waiting > 0:
            response = self.ser.readline().decode('utf-8').strip()
            print(f"Received: {response}")
            return response
        return None

    def close(self):
        self.ser.close()


if __name__ == "__main__":
    sb = SerialBridge()
    try:
        while True:
            sb.send_command("MOVE_FORWARD 150")
            time.sleep(1)
            sb.send_command("STOP")
            time.sleep(1)
            sb.read_response()
    except KeyboardInterrupt:
        sb.close()
