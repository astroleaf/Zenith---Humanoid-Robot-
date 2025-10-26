# Skeleton script to automate video capture of demo session
import subprocess
import time

def record_demo(duration=30, output="demo.mp4"):
    print("Starting camera recording...")
    cmd = ["ffmpeg", "-t", str(duration), "-f", "v4l2", "-i", "/dev/video0", output]
    subprocess.run(cmd)
    print(f"Demo recording saved to {output}")

if __name__ == "__main__":
    record_demo()
