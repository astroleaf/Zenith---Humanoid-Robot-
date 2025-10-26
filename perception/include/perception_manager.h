#ifndef PERCEPTION_MANAGER_H
#define PERCEPTION_MANAGER_H

#include "camera_interface.h"
#include "object_detector.h"
#include "gesture_classifier.h"
#include "face_tracker.h"
#include "sensor_fusion.h"
#include <string>

class PerceptionManager {
public:
    PerceptionManager();
    void initialize(const std::string& objectModel, const std::string& gestureModel);
    void processFrame();

private:
    CameraInterface camera;
    ObjectDetector objectDetector;
    GestureClassifier gestureClassifier;
    FaceTracker faceTracker;
    SensorFusion sensorFusion;
};

#endif
