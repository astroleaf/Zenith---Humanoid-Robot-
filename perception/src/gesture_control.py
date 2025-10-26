import cv2
import tensorflow as tf
import numpy as np

class GestureRecognizer:
    def __init__(self, model_path):
        self.model = tf.keras.models.load_model(model_path)

    def classify(self, frame):
        img = cv2.resize(frame, (64, 64))
        img = img.reshape((1, 64, 64, 3))
        img = img.astype('float32') / 255.0
        pred = self.model.predict(img)
        class_id = np.argmax(pred)
        confidence = np.max(pred)
        return class_id, confidence
