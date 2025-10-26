from comms.comms_manager import CommsManager

def test_command_dispatcher():
    cm = CommsManager()
    cm.move_forward(100)
    cm.turn_left(100)
    cm.stop()
    print("Command dispatcher test executed.")

if __name__ == "__main__":
    test_command_dispatcher()
