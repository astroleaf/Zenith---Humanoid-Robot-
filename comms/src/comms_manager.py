from serial_bridge import SerialBridge
from wifi_socket import WiFiSocket
from bluetooth_module import BluetoothModule

class CommsManager:
    """
    Centralized communication manager — routes between serial, WiFi, and Bluetooth channels.
    """
    def __init__(self, mode='serial', **kwargs):
        self.mode = mode
        if mode == 'serial':
            self.channel = SerialBridge(**kwargs)
        elif mode == 'wifi':
            self.channel = WiFiSocket(**kwargs)
        elif mode == 'bluetooth':
            self.channel = BluetoothModule(**kwargs)
        else:
            raise ValueError(f"Unsupported communication mode: {mode}")

    def send_command(self, command, payload=None):
        msg = {"command": command, "payload": payload or {}}
        if self.mode == 'serial':
            self.channel.send(command + (f" {payload}" if payload else ""))
        else:
            self.channel.send(msg)

    def get_feedback(self):
        return self.channel.receive()

    def close(self):
        self.channel.close()

if __name__ == "__main__":
    cm = CommsManager(mode='serial', port='/dev/ttyUSB0')
    try:
        cm.send_command("MOVE_FORWARD", {"speed": 150})
        while True:
            data = cm.get_feedback()
            if data:
                print("Feedback:", data)
    except KeyboardInterrupt:
        cm.close()
