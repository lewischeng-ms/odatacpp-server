﻿//---------------------------------------------------------------------
// <copyright file="edm_singleton.h" company="Microsoft">
//      Copyright (C) Microsoft Corporation. All rights reserved. See License.txt in the project root for license information.
// </copyright>
//---------------------------------------------------------------------

#pragma once

#include "odata/common/utility.h"
#include "odata/edm/edm_type.h"

namespace odata { namespace edm
{

class edm_entity_container;

/// <summary>
/// Represents a set of entities in a container
/// </summary>
class edm_singleton  : public edm_navigation_source
{
public:
    /// <summary>
    /// Constructor
    /// </summary>
    /// <param name="name">The name of the entity set.</param>
    edm_singleton(::odata::utility::string_t name, ::odata::utility::string_t type) 
		: m_type_name(type), edm_navigation_source(name, container_resource_type::E_RESOURCE_SINGLETON)
    {}

	edm_singleton(::odata::utility::string_t name, std::shared_ptr<edm_entity_type> type) 
		: m_entity_type(type), edm_navigation_source(name, container_resource_type::E_RESOURCE_SINGLETON)
    {}

    /// <summary>
    /// Gets the name of the entity set
    /// </summary>
    /// <returns>The name of the entity set.</returns>
    const ::odata::utility::string_t& get_name() const 
    {
        return m_name;
    }

    /// <summary>
    /// Gets the name of the type of the entity set
    /// </summary>
    /// <returns>The name of the type of the entity set.</returns>
    const ::odata::utility::string_t& get_entity_type_name() const 
    {
        return m_type_name;
    }

	std::shared_ptr<edm_entity_type> get_entity_type() const
	{
		return m_entity_type.lock();
	}

	void set_entity_type(const std::shared_ptr<edm_entity_type>& entity_type)
	{
		m_entity_type = entity_type;
	}

private:
    friend class edm_entity_container;
    ::odata::utility::string_t m_type_name;
	std::weak_ptr<edm_entity_type> m_entity_type;
};

}}