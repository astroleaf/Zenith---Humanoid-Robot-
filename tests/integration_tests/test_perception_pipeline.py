from perception.perception_pipeline import PerceptionPipeline

def test_pipeline():
    pipeline = PerceptionPipeline('models/object_detector.tflite', 'models/gesture_model.h5')
    results = pipeline.run()
    assert 'gesture' in results
    assert 'objects' in results
    print("Perception pipeline test PASSED.")

if __name__ == "__main__":
    test_pipeline()
