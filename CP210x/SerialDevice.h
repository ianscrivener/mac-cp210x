/*
 * Author: Landon Fuller <landonf@plausible.coop>
 *
 * Copyright (c) 2012 Plausible Labs Cooperative, Inc.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef CP210x_SerialDevice_h
#define CP210x_SerialDevice_h

#include <libkern/c++/OSContainers.h>

#include <IOKit/usb/IOUSBDevice.h>

#include <IOKit/serial/IOSerialStreamSync.h>

namespace coop_plausible {

/**
 * Manages the IOKit IOSerialStreamSync and its backing
 * device node.
 */
class SerialDevice : public OSObject {
    OSDeclareDefaultStructors(SerialDevice);

private:
    IOSerialStreamSync *_stream;
    
public:
    virtual bool init (IOUSBDevice *device);
    virtual void free ();

private:
    OSString *getDeviceNameSuffix (IOUSBDevice *device);
};


}

#endif
