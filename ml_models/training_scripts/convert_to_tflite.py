import tensorflow as tf

def convert_to_tflite(saved_model_path, tflite_output_path):
    converter = tf.lite.TFLiteConverter.from_keras_model_file(saved_model_path)
    converter.optimizations = [tf.lite.Optimize.DEFAULT]
    tflite_model = converter.convert()
    with open(tflite_output_path, 'wb') as f:
        f.write(tflite_model)
    print(f"Converted and saved TFLite model to {tflite_output_path}")

if __name__ == "__main__":
    convert_to_tflite('gesture_model.h5', '../gesture_model.tflite')
