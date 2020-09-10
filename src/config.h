/* This Source Code Form is subject to the terms of the JCZ-Automatisering License, v1.0. */
/* For more information, see the LICENSE file in the toplevel directory of this archive or package. */
/* Copyright 2020 - JCZ-Automatisering */

/**
 * @file config.h
 * @copybrief jczconfig::Config
 */

#pragma once

#include <string>
#include <vector>

#include "config_section.h"

namespace jczconfig
{
    /**
     * @class Config
     * @brief Configuration file handler.
     */
    class Config
    {
        public:
            Config(void);
            virtual ~Config(void) {}

            virtual bool load(const std::string &config_data);

            virtual std::vector<ConfigSection> get_sections(void) const;
            virtual ConfigSection get_section(const std::string &section_name) const;
            virtual bool has_section(const std::string &section_name) const;

            virtual std::string get_section_member(const std::string &section, const std::string &member,
                                                   const std::string &default_value = "") const;

            virtual std::string to_string(void) const;

            virtual bool status(void) const;

            virtual void clear(void);       /** < @brief Clear the configuration state to 'zero' */

        protected:    /* Members */
            std::vector<ConfigSection> sections;
    };
}
