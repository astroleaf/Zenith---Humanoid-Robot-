# ML Models Directory

This directory contains the scripts and serialized models for:
- Gesture recognition
- Object detection
- Model conversion and quantization

## Training
- Use `training_scripts/train_gesture_model.py` to train gesture classifier.
- Use `training_scripts/train_object_recognition.py` to train object recognition model.

## Conversion
- Convert Keras models to TensorFlow Lite with `convert_to_tflite.py`.

## Models
- Place `.tflite` models here for inference on the robot SBC.
