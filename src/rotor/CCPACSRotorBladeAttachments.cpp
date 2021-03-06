/*
* Copyright (C) 2007-2014 German Aerospace Center (DLR/SC)
*
* Created: 2014-04-11 Philipp Kunze <Philipp.Kunze@dlr.de>
* Changed: $Id$
*
* Version: $Revision$
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
/**
* @file
* @brief  Implementation of CPACS rotor blade attachments handling routines.
*/

#include "CCPACSRotorBladeAttachments.h"
#include "CCPACSRotor.h"
#include "CTiglError.h"
#include <iostream>
#include <sstream>

namespace tigl
{

// Constructor
CCPACSRotorBladeAttachments::CCPACSRotorBladeAttachments(CCPACSRotor* rotor)
    : rotor(rotor)
{
    Cleanup();
}

// Destructor
CCPACSRotorBladeAttachments::~CCPACSRotorBladeAttachments(void)
{
    Cleanup();
}

// Cleanup routine
void CCPACSRotorBladeAttachments::Cleanup(void)
{
    for (CCPACSRotorBladeAttachmentContainer::size_type i = 0; i < rotorBladeAttachments.size(); i++) {
        delete rotorBladeAttachments[i];
    }
    rotorBladeAttachments.clear();
}

// Invalidates internal state
void CCPACSRotorBladeAttachments::Invalidate(void)
{
    for (int i = 1; i <= GetRotorBladeAttachmentCount(); i++) {
        GetRotorBladeAttachment(i).Invalidate();
    }
}

// Read CPACS rotorBladeAttachments elements
void CCPACSRotorBladeAttachments::ReadCPACS(TixiDocumentHandle tixiHandle, const std::string rotorBladeAttachmentsXPath, const std::string rotorBladeAttachmentElementName)
{
    Cleanup();

    /* Get rotorBladeAttachment element count */
    int elementCount;
    if (tixiGetNamedChildrenCount(tixiHandle, rotorBladeAttachmentsXPath.c_str(), rotorBladeAttachmentElementName.c_str(), &elementCount) != SUCCESS) {
        throw CTiglError("XML error: tixiGetNamedChildrenCount failed in CCPACSRotorBladeAttachments::ReadCPACS", TIGL_XML_ERROR);
    }

    // Loop over all rotorBladeAttachment elements
    for (int i = 1; i <= elementCount; i++) {
        CCPACSRotorBladeAttachment* rotorBladeAttachment = new CCPACSRotorBladeAttachment(rotor);
        rotorBladeAttachments.push_back(rotorBladeAttachment);

        std::ostringstream xpath;
        xpath << rotorBladeAttachmentsXPath << "/" << rotorBladeAttachmentElementName << "[" << i << "]";
        rotorBladeAttachment->ReadCPACS(tixiHandle, xpath.str());
    }
}

// Returns the total count of rotor blade attachments in a rotor hub
int CCPACSRotorBladeAttachments::GetRotorBladeAttachmentCount(void) const
{
    return static_cast<int>(rotorBladeAttachments.size());
}

// Returns the rotor blade attachment for a given index.
CCPACSRotorBladeAttachment& CCPACSRotorBladeAttachments::GetRotorBladeAttachment(int index) const
{
    index--;
    if (index < 0 || index >= GetRotorBladeAttachmentCount()) {
        throw CTiglError("Error: Invalid index in CCPACSRotorBladeAttachments::GetRotorBladeAttachment", TIGL_INDEX_ERROR);
    }
    return (*rotorBladeAttachments[index]);
}

// Returns the parent rotor
CCPACSRotor& CCPACSRotorBladeAttachments::GetRotor(void) const
{
    return *rotor;
}

// Returns the parent configuration
CCPACSConfiguration& CCPACSRotorBladeAttachments::GetConfiguration(void) const
{
    return rotor->GetConfiguration();
}

} // end namespace tigl
