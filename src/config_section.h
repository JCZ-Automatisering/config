/* This Source Code Form is subject to the terms of the JCZ-Automatisering License, v1.0. */
/* For more information, see the LICENSE file in the toplevel directory of this archive or package. */
/* Copyright 2020 - JCZ-Automatisering */

#pragma once

#include <string>
#include <vector>

#include "config_value.h"

namespace jczconfig
{
    /**
     * @class ConfigSection
     * @brief For every section of an ini file, a ConfigSection class will be created.
     *
     * The ConfigSection class holds a vector of key/value pairs (ConfigValue) in it's section.
     */
    class ConfigSection
    {
        public:
            explicit ConfigSection(const std::string &section_name);

            std::vector<ConfigValue> section_members;
            std::string to_string(void) const;
            std::string get_name(void) const;

            bool has_member(const std::string &section_name) const;
            bool has_members(const std::vector<std::string> &names) const;

            std::string get_member(const std::string &member) const;

        private:    /* Members */
            std::string section_name;
    };
}
