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
* @brief  Implementation of CPACS fuselage section elements handling routines.
*/

#ifndef CCPACSFUSELAGESECTIONELEMENTS_H
#define CCPACSFUSELAGESECTIONELEMENTS_H

#include "tigl_internal.h"
#include "tixi.h"
#include "CCPACSFuselageSectionElement.h"
#include <string>
#include <vector>

namespace tigl
{

class CCPACSFuselageSectionElements
{

private:
    // Typedef for a CCPACSFuselageSectionElement container to store the profiles of a section.
    typedef std::vector<CCPACSFuselageSectionElement*> CCPACSFuselageSectionElementContainer;

public:
    // Constructor
    TIGL_EXPORT CCPACSFuselageSectionElements(void);

    // Virtual Destructor
    TIGL_EXPORT virtual ~CCPACSFuselageSectionElements(void);

    // Read CPACS section elements
    TIGL_EXPORT void ReadCPACS(TixiDocumentHandle tixiHandle, const std::string& sectionXPath);

    // Write CPACS section elements
    TIGL_EXPORT void WriteCPACS(TixiDocumentHandle tixiHandle, const std::string& sectionXPath);

    // Get element count for this section
    TIGL_EXPORT int GetSectionElementCount(void) const;

    // Get element for a given index
    TIGL_EXPORT CCPACSFuselageSectionElement& GetSectionElement(int index) const;

protected:
    // Cleanup routine
    void Cleanup(void);

private:
    // Copy constructor
    CCPACSFuselageSectionElements(const CCPACSFuselageSectionElements& ) { /* Do nothing */ }

    // Assignment operator
    void operator=(const CCPACSFuselageSectionElements& ) { /* Do nothing */ }

private:
    CCPACSFuselageSectionElementContainer elements; /**< Section elements */

};

} // end namespace tigl

#endif // CCPACSFUSELAGESECTIONELEMENTS_H
