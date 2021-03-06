/* 
* Copyright (C) 2007-2013 German Aerospace Center (DLR/SC)
*
* Created: 2010-08-13 Markus Litz <Markus.Litz@dlr.de>
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
* @brief  Implementation of CPACS wing section handling routines.
*/

#include "CCPACSWingSection.h"
#include "CTiglError.h"
#include "TixiSaveExt.h"
#include <iostream>

namespace tigl
{

// Constructor
CCPACSWingSection::CCPACSWingSection()
{
    Cleanup();
}

// Destructor
CCPACSWingSection::~CCPACSWingSection(void)
{
    Cleanup();
}

// Cleanup routine
void CCPACSWingSection::Cleanup(void)
{
    name = "";
    uID  = "";
    description = "";
    transformation.reset();
}

// Read CPACS section elements
void CCPACSWingSection::ReadCPACS(TixiDocumentHandle tixiHandle, const std::string& sectionXPath)
{
    Cleanup();

    // Get subelement "name"
    char* ptrName = NULL;
    if (tixiGetTextElement(tixiHandle, (sectionXPath + "/name").c_str(), &ptrName) == SUCCESS) {
        name = ptrName;
    }

    // Get subelement "description"
    char* ptrDescription = NULL;
    if (tixiGetTextElement(tixiHandle, (sectionXPath + "/description").c_str(), &ptrDescription) == SUCCESS) {
        description = ptrDescription;
    }

    // Get attribute "uID"
    char* ptrUID = NULL;
    if (tixiGetTextAttribute(tixiHandle, sectionXPath.c_str(), "uID", &ptrUID) == SUCCESS) {
        uID = ptrUID;
    }

    // Get Transformation
    transformation.ReadCPACS(tixiHandle, sectionXPath);

    // Get subelement "elements", which means the section elements
    elements.ReadCPACS(tixiHandle, sectionXPath);
}

// Write CPACS section elements
void CCPACSWingSection::WriteCPACS(TixiDocumentHandle tixiHandle, const std::string& sectionXPath)
{
    TixiSaveExt::TixiSaveTextElement(tixiHandle, sectionXPath.c_str(), "name", GetName().c_str());
    TixiSaveExt::TixiSaveTextElement(tixiHandle, sectionXPath.c_str(), "description", description.c_str());
    TixiSaveExt::TixiSaveTextAttribute(tixiHandle, sectionXPath.c_str(), "uID", GetUID().c_str());

    transformation.WriteCPACS(tixiHandle, sectionXPath);

    elements.WriteCPACS(tixiHandle, sectionXPath);
}

// Get profile count for this section
int CCPACSWingSection::GetSectionElementCount(void) const
{
    return elements.GetSectionElementCount();
}

// Get the UID of this WingSection
const std::string& CCPACSWingSection::GetUID(void) const
{
    return uID;
}

// Get the name of this WingSection
const std::string& CCPACSWingSection::GetName() const
{
    return name;
}

// Getter for the member description
const std::string& CCPACSWingSection::GetDescription(void) const
{
    return description;
}

// Get element for a given index
CCPACSWingSectionElement& CCPACSWingSection::GetSectionElement(int index) const
{
    return elements.GetSectionElement(index);
}

// Gets the section transformation
CTiglTransformation CCPACSWingSection::GetSectionTransformation(void) const
{
    return transformation.getTransformationMatrix();
}

// Gets the section translation
const CTiglPoint& CCPACSWingSection::GetTranslation() const
{
    return transformation.getTranslationVector();
}

// Gets the section rotation
const CTiglPoint& CCPACSWingSection::GetRotation() const
{
    return transformation.getRotation();
}

// Gets the section scaling
const CTiglPoint& CCPACSWingSection::GetScaling() const
{
    return transformation.getScaling();
}

// Setter for translation
void CCPACSWingSection::SetTranslation(const CTiglPoint& trans)
{
    transformation.setTranslation(trans, ABS_LOCAL);
    transformation.updateMatrix();

}

// Setter for rotation
void CCPACSWingSection::SetRotation(const CTiglPoint& rot)
{
    transformation.setRotation(rot);
    transformation.updateMatrix();
}

// Setter for scaling
void CCPACSWingSection::SetScaling(const CTiglPoint& scale)
{
    transformation.setScaling(scale);
    transformation.updateMatrix();
}

} // end namespace tigl
