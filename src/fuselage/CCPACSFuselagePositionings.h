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
* @brief  Implementation of CPACS fuselage positionings handling routines.
*/

#ifndef CCPACSFUSELAGEPOSITIONINGS_H
#define CCPACSFUSELAGEPOSITIONINGS_H

#include "tigl_internal.h"
#include "tixi.h"
#include "CCPACSFuselagePositioning.h"
#include "CTiglError.h"
#include <string>
#include <vector>
#include <map>

namespace tigl
{

class CCPACSFuselagePositionings
{

private:
    // Typedef for a CCPACSFuselagePositioning container to store the positionings.
    typedef std::map<std::string, CCPACSFuselagePositioning*> CCPACSFuselagePositioningContainer;
    typedef CCPACSFuselagePositioningContainer::iterator CCPACSFuselagePositioningIterator;

public:
    // Constructor
    TIGL_EXPORT CCPACSFuselagePositionings(void);

    // Virtual Destructor
    TIGL_EXPORT virtual ~CCPACSFuselagePositionings(void);

    // Read CPACS positionings element
    TIGL_EXPORT void ReadCPACS(TixiDocumentHandle tixiHandle, const std::string& fuselageXPath);

    // Write CPACS positionings element
    TIGL_EXPORT void WriteCPACS(TixiDocumentHandle tixiHandle, const std::string& fuselageXPath);

    // Invalidates internal state
    TIGL_EXPORT void Invalidate(void);

    // Returns the positioning matrix for a given section index
    TIGL_EXPORT CTiglTransformation GetPositioningTransformation(std::string sectionIndex);

protected:
    // Cleanup routine
    void Cleanup(void);

    // Update internal positioning structure
    void Update(void);

    // Update connected positionings by recursion
    void UpdateNextPositioning(CCPACSFuselagePositioning*, int depth);

private:
    // Copy constructor
    CCPACSFuselagePositionings(const CCPACSFuselagePositionings& );

    // Assignment operator
    void operator=(const CCPACSFuselagePositionings& );

private:
    CCPACSFuselagePositioningContainer positionings;    /**< Positioning elements */
    bool                               invalidated;     /**< Internal state flag  */

};

} // end namespace tigl

#endif // CCPACSFUSELAGEPOSITIONINGS_H
