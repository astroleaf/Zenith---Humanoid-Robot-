from camera_stream import CameraStream
from object_detection import ObjectDetector
from gesture_control import GestureRecognizer
from face_tracker import FaceTracker

class PerceptionPipeline:
    def __init__(self,
                 object_model_path,
                 gesture_model_path):
        self.camera = CameraStream(0)
        self.detector = ObjectDetector(object_model_path)
        self.gesture_recognizer = GestureRecognizer(gesture_model_path)
        self.face_tracker = FaceTracker()

    def run(self):
        frame = self.camera.read_frame()
        objects = self.detector.detect(frame)
        gesture, conf = self.gesture_recognizer.classify(frame)
        faces = self.face_tracker.detect_faces(frame)
        return {
            'frame': frame,
            'objects': objects,
            'gesture': gesture,
            'gesture_confidence': conf,
            'faces': faces
        }

    def release(self):
        self.camera.release()
