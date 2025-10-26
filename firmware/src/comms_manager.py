from serial_bridge import SerialBridge

class CommsManager:
    def __init__(self, port='/dev/ttyUSB0'):
        self.bridge = SerialBridge(port=port)

    def move_forward(self, speed):
        self.bridge.send_command(f"MOVE_FORWARD {speed}")

    def move_backward(self, speed):
        self.bridge.send_command(f"MOVE_BACKWARD {speed}")

    def turn_left(self, speed):
        self.bridge.send_command(f"TURN_LEFT {speed}")

    def turn_right(self, speed):
        self.bridge.send_command(f"TURN_RIGHT {speed}")

    def stop(self):
        self.bridge.send_command("STOP")

    def close(self):
        self.bridge.close()
