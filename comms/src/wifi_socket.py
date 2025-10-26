import socket
import json

class WiFiSocket:
    """
    TCP/IP socket communication for wireless humanoid control.
    """
    def __init__(self, host='0.0.0.0', port=8888):
        self.server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.server.bind((host, port))
        self.server.listen(1)
        print(f"WiFiSocket listening on {host}:{port}")
        self.client, self.addr = self.server.accept()
        print(f"Connection established → {self.addr}")

    def send(self, data_dict):
        data = json.dumps(data_dict).encode('utf-8')
        self.client.sendall(data + b'\n')
        print(f"Sent over WiFi: {data_dict}")

    def receive(self):
        raw = self.client.recv(1024).decode('utf-8').strip()
        if raw:
            try:
                data = json.loads(raw)
                print(f"Received over WiFi: {data}")
                return data
            except:
                print(f"Non‑JSON message: {raw}")
        return None

    def close(self):
        self.client.close()
        self.server.close()
        print("WiFiSocket session closed.")
