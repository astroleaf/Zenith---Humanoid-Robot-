import cv2
import numpy as np
import tensorflow as tf

class ObjectDetector:
    def __init__(self, model_path):
        self.interpreter = tf.lite.Interpreter(model_path=model_path)
        self.interpreter.allocate_tensors()
        input_details = self.interpreter.get_input_details()
        output_details = self.interpreter.get_output_details()
        self.input_index = input_details[0]['index']
        self.output_index = output_details[0]['index']

    def detect(self, frame):
        input_shape = self.interpreter.get_input_details()[0]['shape']
        img = cv2.resize(frame, (input_shape[2], input_shape[1]))
        img = np.expand_dims(img, axis=0)
        img = img.astype(np.float32) / 255.0
        self.interpreter.set_tensor(self.input_index, img)
        self.interpreter.invoke()
        output = self.interpreter.get_tensor(self.output_index)
        return output
