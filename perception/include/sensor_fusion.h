#ifndef SENSOR_FUSION_H
#define SENSOR_FUSION_H

#include <vector>

struct SensorData {
    float ultrasonicDistance;
    float imuTilt;
    float temperature;
};

class SensorFusion {
public:
    SensorFusion();
    SensorData fuse(const SensorData& sensorData);
    float getConfidenceEstimate();

private:
    float confidenceScore;
};

#endif
