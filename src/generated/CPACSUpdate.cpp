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

#include "CPACSUpdate.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "TixiHelper.h"

namespace tigl
{
    namespace generated
    {
        CPACSUpdate::CPACSUpdate() {}
        
        CPACSUpdate::~CPACSUpdate() {}
        
        void CPACSUpdate::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read element modification
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/modification")) {
                m_modification = tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/modification");
                if (m_modification.empty()) {
                    LOG(ERROR) << "Required element modification is empty at xpath " << xpath;
                }
            }
            else {
                LOG(ERROR) << "Required element modification is missing at xpath " << xpath;
            }
            
            // read element creator
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/creator")) {
                m_creator = tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/creator");
                if (m_creator.empty()) {
                    LOG(ERROR) << "Required element creator is empty at xpath " << xpath;
                }
            }
            else {
                LOG(ERROR) << "Required element creator is missing at xpath " << xpath;
            }
            
            // read element timestamp
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/timestamp")) {
                m_timestamp = tixihelper::TixiGetElement<std::time_t>(tixiHandle, xpath + "/timestamp");
            }
            else {
                LOG(ERROR) << "Required element timestamp is missing at xpath " << xpath;
            }
            
            // read element version
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/version")) {
                m_version = tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/version");
                if (m_version.empty()) {
                    LOG(ERROR) << "Required element version is empty at xpath " << xpath;
                }
            }
            else {
                LOG(ERROR) << "Required element version is missing at xpath " << xpath;
            }
            
            // read element cpacsVersion
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/cpacsVersion")) {
                m_cpacsVersion = tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/cpacsVersion");
                if (m_cpacsVersion.empty()) {
                    LOG(ERROR) << "Required element cpacsVersion is empty at xpath " << xpath;
                }
            }
            else {
                LOG(ERROR) << "Required element cpacsVersion is missing at xpath " << xpath;
            }
            
        }
        
        void CPACSUpdate::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write element modification
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/modification");
            tixihelper::TixiSaveElement(tixiHandle, xpath + "/modification", m_modification);
            
            // write element creator
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/creator");
            tixihelper::TixiSaveElement(tixiHandle, xpath + "/creator", m_creator);
            
            // write element timestamp
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/timestamp");
            tixihelper::TixiSaveElement(tixiHandle, xpath + "/timestamp", m_timestamp);
            
            // write element version
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/version");
            tixihelper::TixiSaveElement(tixiHandle, xpath + "/version", m_version);
            
            // write element cpacsVersion
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/cpacsVersion");
            tixihelper::TixiSaveElement(tixiHandle, xpath + "/cpacsVersion", m_cpacsVersion);
            
        }
        
        const std::string& CPACSUpdate::GetModification() const
        {
            return m_modification;
        }
        
        void CPACSUpdate::SetModification(const std::string& value)
        {
            m_modification = value;
        }
        
        const std::string& CPACSUpdate::GetCreator() const
        {
            return m_creator;
        }
        
        void CPACSUpdate::SetCreator(const std::string& value)
        {
            m_creator = value;
        }
        
        const std::time_t& CPACSUpdate::GetTimestamp() const
        {
            return m_timestamp;
        }
        
        void CPACSUpdate::SetTimestamp(const std::time_t& value)
        {
            m_timestamp = value;
        }
        
        const std::string& CPACSUpdate::GetVersion() const
        {
            return m_version;
        }
        
        void CPACSUpdate::SetVersion(const std::string& value)
        {
            m_version = value;
        }
        
        const std::string& CPACSUpdate::GetCpacsVersion() const
        {
            return m_cpacsVersion;
        }
        
        void CPACSUpdate::SetCpacsVersion(const std::string& value)
        {
            m_cpacsVersion = value;
        }
        
    }
}
