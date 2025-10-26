import cv2

class CameraStream:
    def __init__(self, camera_index=0):
        self.cap = cv2.VideoCapture(camera_index)
        if not self.cap.isOpened():
            raise IOError("Cannot open webcam")

    def read_frame(self):
        ret, frame = self.cap.read()
        if not ret:
            raise IOError("Failed to grab frame")
        return frame

    def release(self):
        self.cap.release()
