/////////////////////////////////////////////////////////////////////////////
// Name:            powertabobject.h
// Purpose:         Provides support for polymorphic reading/writing of Power Tab objects
// Author:          Brad Larsen
// Modified by:     
// Created:         Dec 18, 2004
// RCS-ID:          
// Copyright:       (c) Brad Larsen
// License:         wxWindows license
/////////////////////////////////////////////////////////////////////////////

#ifndef __POWERTABOBJECT_H__
#define __POWERTABOBJECT_H__

#include <cstdint>
#include <string>

class PowerTabOutputStream;
class PowerTabInputStream;

/// Provides support for polymorphic reading/writing of Power Tab objects
class PowerTabObject
{
    // Constructor/Destructor
public:

    virtual ~PowerTabObject() {}

    // MFC Class Functions
    /// Gets the MFC Class Name for the object
    /// @return The MFC Class Name
    virtual std::string GetMFCClassName() const = 0;

    /// Gets the MFC Class Schema for the object
    /// @return The MFC Class Schema
    virtual uint16_t GetMFCClassSchema() const = 0;

    // Serialization Functions
    virtual bool Serialize(PowerTabOutputStream& stream) const = 0;
    virtual bool Deserialize(PowerTabInputStream& stream, uint16_t version) = 0;
};

#endif
