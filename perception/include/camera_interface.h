#ifndef CAMERA_INTERFACE_H
#define CAMERA_INTERFACE_H

#include <opencv2/opencv.hpp>

class CameraInterface {
public:
    CameraInterface(int camIndex = 0);
    bool openCamera();
    cv::Mat captureFrame();
    void closeCamera();

private:
    int cameraIndex;
    cv::VideoCapture cap;
    bool isOpen;
};

#endif
