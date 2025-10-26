#ifndef FEATURE_EXTRACTOR_H
#define FEATURE_EXTRACTOR_H

#include <opencv2/opencv.hpp>

class FeatureExtractor {
public:
    FeatureExtractor();
    std::vector<cv::KeyPoint> extractKeypoints(const cv::Mat& frame);
    cv::Mat computeDescriptors(const cv::Mat& frame, std::vector<cv::KeyPoint>& keypoints);

private:
    cv::Ptr<cv::ORB> orb;
};

#endif
