#ifndef OBJECT_DETECTOR_H
#define OBJECT_DETECTOR_H

#include <opencv2/opencv.hpp>
#include <string>
#include <vector>

struct DetectionResult {
    std::string label;
    float confidence;
    cv::Rect box;
};

class ObjectDetector {
public:
    ObjectDetector(const std::string& modelPath, const std::string& labelFile);
    std::vector<DetectionResult> detect(const cv::Mat& frame);

private:
    std::string modelPath;
    std::string labelFile;
};

#endif
