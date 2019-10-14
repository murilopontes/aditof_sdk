#ifndef DEVICE_ENUMERATOR_IMPL_H
#define DEVICE_ENUMERATOR_IMPL_H

#include <aditof/device_enumerator_interface.h>

class DeviceEnumeratorImpl : public aditof::DeviceEnumeratorInterface {
  public:
    ~DeviceEnumeratorImpl() = default;

  public: // implements DeviceEnumeratorInterface
    virtual aditof::Status
    findDevices(std::vector<aditof::DeviceConstructionData> &devices);
};

#endif // DEVICE_ENUMERATOR_IMPL_H
