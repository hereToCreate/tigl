// Copyright (c) 2016 RISC Software GmbH
//
// This file was generated by CPACSGen from CPACS XML Schema (c) German Aerospace Center (DLR/SC).
// Do not edit, all changes are lost when files are re-generated.
//
// Licensed under the Apache License, Version 2.0 (the "License")
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <string>
#include <cctype>

#include "CTiglError.h"
#include "to_string.h"

namespace tigl
{
    namespace generated
    {
        // This enum is used in:
        // CPACSFuselageCutOut_cutoutType
        
        // generated from /xsd:schema/xsd:complexType[359]/xsd:complexContent/xsd:extension/xsd:all/xsd:element[14]/xsd:complexType/xsd:simpleContent
        #ifdef HAVE_CPP11
        enum class CPACSFuselageCutOut_cutoutType_SimpleContent
        #else
        enum CPACSFuselageCutOut_cutoutType_SimpleContent
        #endif
        {
            window,
            door,
            paxDoor,
            emergencyDoor,
            cargoDoor,
            ramp
        };
        
        #ifdef HAVE_CPP11
        inline std::string CPACSFuselageCutOut_cutoutType_SimpleContentToString(const CPACSFuselageCutOut_cutoutType_SimpleContent& value)
        {
            switch(value) {
            case CPACSFuselageCutOut_cutoutType_SimpleContent::window: return "window";
            case CPACSFuselageCutOut_cutoutType_SimpleContent::door: return "door";
            case CPACSFuselageCutOut_cutoutType_SimpleContent::paxDoor: return "paxDoor";
            case CPACSFuselageCutOut_cutoutType_SimpleContent::emergencyDoor: return "emergencyDoor";
            case CPACSFuselageCutOut_cutoutType_SimpleContent::cargoDoor: return "cargoDoor";
            case CPACSFuselageCutOut_cutoutType_SimpleContent::ramp: return "ramp";
            default: throw CTiglError("Invalid enum value \"" + std_to_string(static_cast<int>(value)) + "\" for enum type CPACSFuselageCutOut_cutoutType_SimpleContent");
            }
        }
        inline CPACSFuselageCutOut_cutoutType_SimpleContent stringToCPACSFuselageCutOut_cutoutType_SimpleContent(const std::string& value)
        {
            auto toLower = [](std::string str) { for (char& c : str) { c = std::tolower(c); } return str; };
            if (toLower(value) == "window") { return CPACSFuselageCutOut_cutoutType_SimpleContent::window; }
            if (toLower(value) == "door") { return CPACSFuselageCutOut_cutoutType_SimpleContent::door; }
            if (toLower(value) == "paxdoor") { return CPACSFuselageCutOut_cutoutType_SimpleContent::paxDoor; }
            if (toLower(value) == "emergencydoor") { return CPACSFuselageCutOut_cutoutType_SimpleContent::emergencyDoor; }
            if (toLower(value) == "cargodoor") { return CPACSFuselageCutOut_cutoutType_SimpleContent::cargoDoor; }
            if (toLower(value) == "ramp") { return CPACSFuselageCutOut_cutoutType_SimpleContent::ramp; }
            throw CTiglError("Invalid string value \"" + value + "\" for enum type CPACSFuselageCutOut_cutoutType_SimpleContent");
        }
        #else
        inline std::string CPACSFuselageCutOut_cutoutType_SimpleContentToString(const CPACSFuselageCutOut_cutoutType_SimpleContent& value)
        {
            switch(value) {
            case window: return "window";
            case door: return "door";
            case paxDoor: return "paxDoor";
            case emergencyDoor: return "emergencyDoor";
            case cargoDoor: return "cargoDoor";
            case ramp: return "ramp";
            default: throw CTiglError("Invalid enum value \"" + std_to_string(static_cast<int>(value)) + "\" for enum type CPACSFuselageCutOut_cutoutType_SimpleContent");
            }
        }
        inline CPACSFuselageCutOut_cutoutType_SimpleContent stringToCPACSFuselageCutOut_cutoutType_SimpleContent(const std::string& value)
        {
            struct ToLower { std::string operator()(std::string str) { for (std::size_t i = 0; i < str.length(); i++) { str[i] = std::tolower(str[i]); } return str; } } toLower;
            if (toLower(value) == "window") { return window; }
            if (toLower(value) == "door") { return door; }
            if (toLower(value) == "paxdoor") { return paxDoor; }
            if (toLower(value) == "emergencydoor") { return emergencyDoor; }
            if (toLower(value) == "cargodoor") { return cargoDoor; }
            if (toLower(value) == "ramp") { return ramp; }
            throw CTiglError("Invalid string value \"" + value + "\" for enum type CPACSFuselageCutOut_cutoutType_SimpleContent");
        }
        #endif
    }
    
    // Aliases in tigl namespace
    #ifdef HAVE_CPP11
    using ECPACSFuselageCutOut_cutoutType_SimpleContent = generated::CPACSFuselageCutOut_cutoutType_SimpleContent;
    #else
    typedef generated::CPACSFuselageCutOut_cutoutType_SimpleContent ECPACSFuselageCutOut_cutoutType_SimpleContent;
    #endif
}