/* This Source Code Form is subject to the terms of the JCZ-Automatisering License, v1.0. */
/* For more information, see the LICENSE file in the toplevel directory of this archive or package. */
/* Copyright 2020 - JCZ-Automatisering */

#pragma once

#include <string>

namespace jczconfig
{
    /**
     * @class ConfigValue
     * @brief A key / value pair.
     */
    class ConfigValue
    {
        public:
            /** @brief Default constructor. */
            ConfigValue(void) : key(), value() {}
            std::string key;
            std::string value;

            std::string to_string(void) const;
    };
}
