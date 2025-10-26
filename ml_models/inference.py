import tensorflow as tf
import numpy as np

class TFLiteModel:
    def __init__(self, model_path):
        self.interpreter = tf.lite.Interpreter(model_path=model_path)
        self.interpreter.allocate_tensors()
        input_details = self.interpreter.get_input_details()
        output_details = self.interpreter.get_output_details()
        self.input_index = input_details[0]['index']
        self.output_index = output_details[0]['index']

    def infer(self, input_data):
        input_shape = self.interpreter.get_input_details()[0]['shape']
        data = np.array(input_data, dtype=np.float32).reshape(input_shape)
        self.interpreter.set_tensor(self.input_index, data)
        self.interpreter.invoke()
        result = self.interpreter.get_tensor(self.output_index)
        return result
