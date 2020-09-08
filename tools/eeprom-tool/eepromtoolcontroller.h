/*
 * BSD 3-Clause License
 *
 * Copyright (c) 2019, Analog Devices, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef EEPROMTOOLCONTROLLER_H
#define EEPROMTOOLCONTROLLER_H

#include <aditof/camera.h>
#include <aditof/device_interface.h>
#include <aditof/frame.h>
#include <aditof/system.h>
#include <aditof/eeprom_interface.h>
#include "eeprom_list.h"

#include <atomic>
#include <functional>
#include <memory>
#include <thread>

class EepromToolController {

  public:
    EepromToolController();
    ~EepromToolController();

    aditof::Status setConnection(aditof::ConnectionType connectionType, const std::string& ip = "0.0.0.0");
    
    aditof::Status writeFileToEeprom(char const* filename);
    aditof::Status readEepromToFile(char const* filename);
    aditof::Status listEeproms();
  private:
    //EEPROM operations
    aditof::Status writeEeprom(const std::vector<uint8_t> data);
    aditof::Status readEeprom(std::vector<uint8_t>& data);
    //File operations
    static aditof::Status readFile(char const* filename, std::vector<uint8_t>&);
    static aditof::Status writeFile(char const* filename, const std::vector<uint8_t>);
  private:
    aditof::System *m_system;
    std::shared_ptr<aditof::EepromInterface> m_eeprom;
    std::shared_ptr<aditof::DeviceInterface> m_device;
};

#endif
