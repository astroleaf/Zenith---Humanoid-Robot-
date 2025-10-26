#ifndef ML_INTEGRATION_BRIDGE_H
#define ML_INTEGRATION_BRIDGE_H

#include <string>
#include <vector>

class MLIntegrationBridge {
public:
    MLIntegrationBridge(const std::string& socketPath = "/tmp/ml_socket");
    void sendToModelServer(const std::vector<float>& input);
    std::vector<float> receiveModelOutput();

private:
    std::string socketPath;
    int sockfd;
};

#endif
