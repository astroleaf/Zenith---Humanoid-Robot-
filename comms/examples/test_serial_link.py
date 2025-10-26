from serial_bridge import SerialBridge
import time

def test_commands():
    sb = SerialBridge()
    try:
        sb.send_command("MOVE_FORWARD 100")
        time.sleep(2)
        sb.send_command("TURN_LEFT 100")
        time.sleep(2)
        sb.send_command("STOP")
        time.sleep(1)

    except KeyboardInterrupt:
        sb.close()

if __name__ == "__main__":
    test_commands()
