#ifndef DEPTH_ESTIMATOR_H
#define DEPTH_ESTIMATOR_H

#include <opencv2/opencv.hpp>

class DepthEstimator {
public:
    DepthEstimator(float baseline = 0.08f, float focalLength = 700.0f);
    cv::Mat computeDepthMap(const cv::Mat& leftImage, const cv::Mat& rightImage);

private:
    float baseline;
    float focalLength;
};

#endif
