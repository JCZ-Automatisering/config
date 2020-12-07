/* This Source Code Form is subject to the terms of the JCZ-Automatisering License, v1.0. */
/* For more information, see the LICENSE file in the toplevel directory of this archive or package. */
/* Copyright 2020 - JCZ-Automatisering */

#include "config_section.h"

#include <algorithm>

namespace jczconfig
{
    /**
     * @brief Check if config section has a member with the given name.
     * @param name  The name to check.
     * @return True if the member exists.
     */
    bool ConfigSection::has_member(const std::string &name) const
    {
        return std::any_of(this->section_members.begin(), this->section_members.end(), [&name] (const ConfigValue &v)
        {
            return v.key == name;
        });
    }

    /**
     * @brief Check if config section has all members with the given names.
     * @param names Vector of the names to check
     * @return True if all the members exist.
     */
    bool ConfigSection::has_members(const std::vector<std::string> &names) const
    {
        for (const std::string &item: names)
        {
            if (this->has_member(item) == false)
            {
                return false;
            }
        }

        return true;
    }

    /**
     * @brief Get section member.
     * @param member    The member name.
     * @return The value of 'member'.
     */
    std::string ConfigSection::get_member(const std::string &member) const
    {
        for (const ConfigValue &v: this->section_members)
        {
            if (v.key == member)
            {
                return v.value;
            }
        }

        return "";
    }

    /**
     * @brief ConfigSection constructor
     * @param name The name of the config/ini section
     */
    ConfigSection::ConfigSection(const std::string &section_name) :
        section_members(),
        section_name(section_name)
    {
    }

    /**
     * @brief Convert section to string.
     * @return Section as ini "string".
     */
    std::string ConfigSection::to_string(void) const
    {
        std::string data;

        data = "[" + this->section_name + "]\n";
        for (const ConfigValue &item: this->section_members)
        {
            data += item.to_string() + "\n";
        }
        data += "\n";

        return data;
    }

    std::string ConfigSection::get_name(void) const
    {
        return this->section_name;
    }
}
