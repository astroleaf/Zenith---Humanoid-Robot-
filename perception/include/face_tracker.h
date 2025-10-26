#ifndef FACE_TRACKER_H
#define FACE_TRACKER_H

#include <opencv2/opencv.hpp>

class FaceTracker {
public:
    FaceTracker(const std::string& cascadePath = "haarcascade_frontalface_default.xml");
    std::vector<cv::Rect> detectFaces(const cv::Mat& frame);

private:
    cv::CascadeClassifier faceCascade;
};

#endif
