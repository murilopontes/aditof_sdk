#ifndef CAMERA_96OTF1_H
#define CAMERA_96OTF1_H

#include "calibration.h"

#include <aditof/camera.h>

class Camera96Tof1 : public aditof::Camera {
  public:
    Camera96Tof1(aditof::DeviceInterface *device);
    ~Camera96Tof1();

  public: // implements Camera
    aditof::Status initialize();
    aditof::Status start();
    aditof::Status stop();
    aditof::Status setMode(const std::string &mode,
                           const std::string &modeFilename);
    aditof::Status
    getAvailableModes(std::vector<std::string> &availableModes) const;
    aditof::Status setFrameType(const std::string &frameType);
    aditof::Status
    getAvailableFrameTypes(std::vector<std::string> &availableFrameTypes) const;
    aditof::Status requestFrame(aditof::Frame *frame,
                                aditof::FrameUpdateCallback cb);
    aditof::Status getDetails(aditof::CameraDetails &details) const;
    aditof::DeviceInterface *getDevice();

  private:
    aditof::CameraDetails m_details;
    aditof::DeviceInterface *m_device;
    bool m_devStarted;
    Calibration m_calibration;
};

#endif // CAMERA_96OTF1_H
