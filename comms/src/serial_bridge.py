import serial
import time

class SerialBridge:
    """
    Handles direct serial communication with Arduino or other MCU.
    """
    def __init__(self, port='/dev/ttyUSB0', baudrate=115200, timeout=1):
        self.port = port
        self.baudrate = baudrate
        self.timeout = timeout
        try:
            self.conn = serial.Serial(port, baudrate, timeout=timeout)
            time.sleep(2)
            print(f"SerialBridge connected on {port}")
        except Exception as e:
            print(f"Failed to connect on {port}: {e}")
            raise

    def send(self, message):
        if not message.endswith("\n"):
            message += "\n"
        self.conn.write(message.encode('utf-8'))
        print(f"Sent → {message.strip()}")

    def receive(self):
        if self.conn.in_waiting > 0:
            data = self.conn.readline().decode('utf-8').strip()
            if data:
                print(f"Received ← {data}")
            return data
        return None

    def close(self):
        self.conn.close()
        print("SerialBridge connection closed.")

if __name__ == "__main__":
    sb = SerialBridge()
    try:
        while True:
            sb.send("PING")
            response = sb.receive()
            if response:
                print("Arduino:", response)
            time.sleep(1)
    except KeyboardInterrupt:
        sb.close()
