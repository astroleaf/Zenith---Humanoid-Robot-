import bluetooth

class BluetoothModule:
    """
    Simple Bluetooth communication module for humanoid robot.
    Requires PyBluez library.
    """
    def __init__(self, name='Humanoid_BT', uuid="94f39d29-7d6d-437d-973b-fba39e49d4ee"):
        self.name = name
        self.uuid = uuid
        self.server = bluetooth.BluetoothSocket(bluetooth.RFCOMM)
        self.server.bind(("", bluetooth.PORT_ANY))
        self.server.listen(1)
        port = self.server.getsockname()[1]
        bluetooth.advertise_service(self.server, name,
                                    service_id=uuid,
                                    service_classes=[uuid, bluetooth.SERIAL_PORT_CLASS],
                                    profiles=[bluetooth.SERIAL_PORT_PROFILE])
        print(f"{name} Bluetooth server started on RFCOMM port {port}")
        self.client, self.client_info = self.server.accept()
        print(f"Connected to {self.client_info}")

    def send(self, message):
        self.client.send(message + "\n")
        print(f"Bluetooth Sent → {message}")

    def receive(self):
        data = self.client.recv(1024).decode().strip()
        if data:
            print(f"Bluetooth Received ← {data}")
        return data

    def close(self):
        self.client.close()
        self.server.close()
        print("Bluetooth connection closed.")
