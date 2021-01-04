/* This Source Code Form is subject to the terms of the JCZ-Automatisering License, v1.0. */
/* For more information, see the LICENSE file in the toplevel directory of this archive or package. */
/* Copyright 2021 - JCZ-Automatisering */

#pragma once

#include <vector>
#include <string>

namespace jczconfig
{
    class StringHelpers
    {
        public:
            static std::vector<std::string> split_string(const std::string &input, const std::string &regex);
            static std::string trim_string(const std::string &input, const std::string &find = " ");
            static std::string trim_string_remove_new_line(const std::string &input);
            static std::string get_string_between_two_chars(const std::string &input, const char start, const char end);
            static bool string_last_char_is(const std::string &input, const char character);
            static bool string_remove_last_char_if(std::string &input, const char character);
            static std::vector<std::string> split_string_once(const std::string &input, const char split_char);
    };
}
