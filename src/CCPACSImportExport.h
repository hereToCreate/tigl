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
* @brief  Class to build up a OCC-XDE document structure which could be exported
*           in different file types.
*/

#ifndef CCPACSIMPORTEXPORT_H
#define CCPACSIMPORTEXPORT_H

#include "tixi.h"
#include "CTiglError.h"
#include "CCPACSConfiguration.h"
#include <string>

#include "TopoDS_Shape.hxx"
#include "Handle_TDocStd_Document.hxx"


namespace tigl {

	class CCPACSImportExport
	{
	private:
		
	public:
		// Constructor
		CCPACSImportExport(CCPACSConfiguration& config);

		// Virtual Destructor
		virtual ~CCPACSImportExport(void);

		Handle_TDocStd_Document buildXDEStructure();


	protected:
		

	private:
		CCPACSConfiguration&    myConfig;
	};

} // end namespace tigl

#endif // CCPACSIMPORTEXPORT_H
