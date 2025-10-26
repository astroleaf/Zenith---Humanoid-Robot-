#ifndef POSE_ESTIMATOR_H
#define POSE_ESTIMATOR_H

#include <opencv2/opencv.hpp>

class PoseEstimator {
public:
    PoseEstimator(const std::string& modelPath);
    void estimatePose(const cv::Mat& frame);
};

#endif
