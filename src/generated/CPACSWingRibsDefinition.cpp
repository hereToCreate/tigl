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

#include <cassert>
#include "CCPACSWingRibsDefinitions.h"
#include "CPACSWingRibsDefinition.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
    namespace generated
    {
        CPACSWingRibsDefinition::CPACSWingRibsDefinition(CCPACSWingRibsDefinitions* parent, CTiglUIDManager* uidMgr) :
            m_uidMgr(uidMgr), 
            m_ribCrossSection(reinterpret_cast<CCPACSWingRibsDefinition*>(this), m_uidMgr)
        {
            //assert(parent != NULL);
            m_parent = parent;
        }
        
        CPACSWingRibsDefinition::~CPACSWingRibsDefinition()
        {
            if (m_uidMgr && m_uID) m_uidMgr->TryUnregisterObject(*m_uID);
        }
        
        CCPACSWingRibsDefinitions* CPACSWingRibsDefinition::GetParent() const
        {
            return m_parent;
        }
        
        CTiglUIDManager& CPACSWingRibsDefinition::GetUIDManager()
        {
            return *m_uidMgr;
        }
        
        const CTiglUIDManager& CPACSWingRibsDefinition::GetUIDManager() const
        {
            return *m_uidMgr;
        }
        
        void CPACSWingRibsDefinition::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read attribute uID
            if (tixihelper::TixiCheckAttribute(tixiHandle, xpath, "uID")) {
                m_uID = tixihelper::TixiGetAttribute<std::string>(tixiHandle, xpath, "uID");
            }
            
            // read element name
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/name")) {
                m_name = tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/name");
                if (m_name.empty()) {
                    LOG(ERROR) << "Required element name is empty at xpath " << xpath;
                }
            }
            else {
                LOG(ERROR) << "Required element name is missing at xpath " << xpath;
            }
            
            // read element description
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/description")) {
                m_description = tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/description");
            }
            
            // read element ribCrossSection
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/ribCrossSection")) {
                m_ribCrossSection.ReadCPACS(tixiHandle, xpath + "/ribCrossSection");
            }
            else {
                LOG(ERROR) << "Required element ribCrossSection is missing at xpath " << xpath;
            }
            
            // read element ribsPositioning
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/ribsPositioning")) {
                m_ribsPositioning_choice1 = boost::in_place(reinterpret_cast<CCPACSWingRibsDefinition*>(this));
                try {
                    m_ribsPositioning_choice1->ReadCPACS(tixiHandle, xpath + "/ribsPositioning");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read ribsPositioning at xpath " << xpath << ": " << e.what();
                    m_ribsPositioning_choice1 = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read ribsPositioning at xpath " << xpath << ": " << e.getError();
                    m_ribsPositioning_choice1 = boost::none;
                }
            }
            
            // read element ribExplicitPositioning
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/ribExplicitPositioning")) {
                m_ribExplicitPositioning_choice2 = boost::in_place(reinterpret_cast<CCPACSWingRibsDefinition*>(this));
                try {
                    m_ribExplicitPositioning_choice2->ReadCPACS(tixiHandle, xpath + "/ribExplicitPositioning");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read ribExplicitPositioning at xpath " << xpath << ": " << e.what();
                    m_ribExplicitPositioning_choice2 = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read ribExplicitPositioning at xpath " << xpath << ": " << e.getError();
                    m_ribExplicitPositioning_choice2 = boost::none;
                }
            }
            
            if (m_uidMgr && m_uID) m_uidMgr->RegisterObject(*m_uID, *this);
        }
        
        void CPACSWingRibsDefinition::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write attribute uID
            if (m_uID) {
                tixihelper::TixiSaveAttribute(tixiHandle, xpath, "uID", *m_uID);
            } else {
                if (tixihelper::TixiCheckAttribute(tixiHandle, xpath, "uID")) {
                    tixihelper::TixiRemoveAttribute(tixiHandle, xpath, "uID");
                }
            }
            
            // write element name
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/name");
            tixihelper::TixiSaveElement(tixiHandle, xpath + "/name", m_name);
            
            // write element description
            if (m_description) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/description");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/description", *m_description);
            } else {
                if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/description")) {
                    tixihelper::TixiRemoveElement(tixiHandle, xpath + "/description");
                }
            }
            
            // write element ribCrossSection
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/ribCrossSection");
            m_ribCrossSection.WriteCPACS(tixiHandle, xpath + "/ribCrossSection");
            
            // write element ribsPositioning
            if (m_ribsPositioning_choice1) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/ribsPositioning");
                m_ribsPositioning_choice1->WriteCPACS(tixiHandle, xpath + "/ribsPositioning");
            } else {
                if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/ribsPositioning")) {
                    tixihelper::TixiRemoveElement(tixiHandle, xpath + "/ribsPositioning");
                }
            }
            
            // write element ribExplicitPositioning
            if (m_ribExplicitPositioning_choice2) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/ribExplicitPositioning");
                m_ribExplicitPositioning_choice2->WriteCPACS(tixiHandle, xpath + "/ribExplicitPositioning");
            } else {
                if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/ribExplicitPositioning")) {
                    tixihelper::TixiRemoveElement(tixiHandle, xpath + "/ribExplicitPositioning");
                }
            }
            
        }
        
        const boost::optional<std::string>& CPACSWingRibsDefinition::GetUID() const
        {
            return m_uID;
        }
        
        void CPACSWingRibsDefinition::SetUID(const std::string& value)
        {
            if (m_uidMgr) {
                if (m_uID) m_uidMgr->TryUnregisterObject(*m_uID);
                m_uidMgr->RegisterObject(value, *this);
            }
            m_uID = value;
        }
        
        void CPACSWingRibsDefinition::SetUID(const boost::optional<std::string>& value)
        {
            if (m_uidMgr) {
                if (m_uID) m_uidMgr->TryUnregisterObject(*m_uID);
                if (value) m_uidMgr->RegisterObject(*value, *this);
            }
            m_uID = value;
        }
        
        const std::string& CPACSWingRibsDefinition::GetName() const
        {
            return m_name;
        }
        
        void CPACSWingRibsDefinition::SetName(const std::string& value)
        {
            m_name = value;
        }
        
        const boost::optional<std::string>& CPACSWingRibsDefinition::GetDescription() const
        {
            return m_description;
        }
        
        void CPACSWingRibsDefinition::SetDescription(const std::string& value)
        {
            m_description = value;
        }
        
        void CPACSWingRibsDefinition::SetDescription(const boost::optional<std::string>& value)
        {
            m_description = value;
        }
        
        const CCPACSWingRibCrossSection& CPACSWingRibsDefinition::GetRibCrossSection() const
        {
            return m_ribCrossSection;
        }
        
        CCPACSWingRibCrossSection& CPACSWingRibsDefinition::GetRibCrossSection()
        {
            return m_ribCrossSection;
        }
        
        const boost::optional<CCPACSWingRibsPositioning>& CPACSWingRibsDefinition::GetRibsPositioning_choice1() const
        {
            return m_ribsPositioning_choice1;
        }
        
        boost::optional<CCPACSWingRibsPositioning>& CPACSWingRibsDefinition::GetRibsPositioning_choice1()
        {
            return m_ribsPositioning_choice1;
        }
        
        const boost::optional<CPACSWingRibExplicitPositioning>& CPACSWingRibsDefinition::GetRibExplicitPositioning_choice2() const
        {
            return m_ribExplicitPositioning_choice2;
        }
        
        boost::optional<CPACSWingRibExplicitPositioning>& CPACSWingRibsDefinition::GetRibExplicitPositioning_choice2()
        {
            return m_ribExplicitPositioning_choice2;
        }
        
    }
}
