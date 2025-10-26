#ifndef GESTURE_CLASSIFIER_H
#define GESTURE_CLASSIFIER_H

#include <opencv2/opencv.hpp>
#include <string>

class GestureClassifier {
public:
    GestureClassifier(const std::string& modelPath);
    std::string classifyGesture(const cv::Mat& frame, float& confidence);

private:
    std::string modelPath;
};

#endif

