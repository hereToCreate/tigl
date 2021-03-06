/* 
* Copyright (C) 2016 Airbus Defence and Space
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
#ifndef CCPACSWINGRIBSDEFINITIONS_H
#define CCPACSWINGRIBSDEFINITIONS_H

#include <string>
#include <vector>

#include <tixi.h>

#include "tigl_internal.h"


namespace tigl
{
// forward declarations
class CCPACSWingRibsDefinition;
class CCPACSWingCSStructure;

class CCPACSWingRibsDefinitions
{
private:
    typedef std::vector<CCPACSWingRibsDefinition*> CCPACSWingRibsDefinitionContainer;

public:
    TIGL_EXPORT CCPACSWingRibsDefinitions(CCPACSWingCSStructure& structure);
    TIGL_EXPORT virtual ~CCPACSWingRibsDefinitions();

    TIGL_EXPORT void Invalidate();

    TIGL_EXPORT void ReadCPACS(TixiDocumentHandle tixiHandle, const std::string & ribsDefinitionsXPath);
    TIGL_EXPORT void WriteCPACS(TixiDocumentHandle tixiHandle, const std::string & ribsDefinitionsXPath) const;

    TIGL_EXPORT int GetRibsDefinitionCount() const;

    TIGL_EXPORT const CCPACSWingRibsDefinition& GetRibsDefinition(int index) const;
    TIGL_EXPORT CCPACSWingRibsDefinition& GetRibsDefinition(int index);

    TIGL_EXPORT const CCPACSWingRibsDefinition& GetRibsDefinition(const std::string& uid) const;
    TIGL_EXPORT CCPACSWingRibsDefinition& GetRibsDefinition(const std::string& uid);

protected:
    void Cleanup(void);

private:
    CCPACSWingRibsDefinitions(const CCPACSWingRibsDefinitions& );
    void operator=(const CCPACSWingRibsDefinitions& );

private:
    CCPACSWingCSStructure& structure;
    CCPACSWingRibsDefinitionContainer ribsDefinitions;
};

} // end namespace tigl

#endif // CCPACSWINGRIBSDEFINITIONS_H
