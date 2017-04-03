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

#include "CPACSFuselageCutOut_cutoutType.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "TixiHelper.h"

namespace tigl
{
    namespace generated
    {
        CPACSFuselageCutOut_cutoutType::CPACSFuselageCutOut_cutoutType(){}
        CPACSFuselageCutOut_cutoutType::~CPACSFuselageCutOut_cutoutType() {}
        
        void CPACSFuselageCutOut_cutoutType::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read simpleContent 
            if (tixihelper::TixiCheckElement(tixiHandle, xpath)) {
                m_simpleContent = stringToCPACSFuselageCutOut_cutoutType_SimpleContent(tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/"));
            }
            else {
                LOG(ERROR) << "Required simpleContent  is missing at xpath " << xpath;
            }
            
        }
        
        void CPACSFuselageCutOut_cutoutType::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write simpleContent 
            tixihelper::TixiSaveElement(tixiHandle, xpath + "/", CPACSFuselageCutOut_cutoutType_SimpleContentToString(m_simpleContent));
            
        }
        
        const CPACSFuselageCutOut_cutoutType_SimpleContent& CPACSFuselageCutOut_cutoutType::GetSimpleContent() const
        {
            return m_simpleContent;
        }
        
        void CPACSFuselageCutOut_cutoutType::SetSimpleContent(const CPACSFuselageCutOut_cutoutType_SimpleContent& value)
        {
            m_simpleContent = value;
        }
        
    }
}