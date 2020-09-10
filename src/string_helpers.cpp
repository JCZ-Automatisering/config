/* This Source Code Form is subject to the terms of the JCZ-Automatisering License, v1.0. */
/* For more information, see the LICENSE file in the toplevel directory of this archive or package. */
/* Copyright 2020 - JCZ-Automatisering */

#include "string_helpers.h"

#include <regex>

namespace jczconfig
{
    /**
     * @brief Split the string according to the specified regular expression
     * @param input The input string
     * @param regex The regular expression
     * @return Vector/list of strings
     */
    std::vector<std::string> StringHelpers::split_string(const std::string &input, const std::string &regex)
    {
        const std::regex re(regex);
        std::sregex_token_iterator first{input.begin(), input.end(), re, -1}, last;

        return {first, last};
    }

    /**
     * @brief Trim spaces at the start and end of the string
     * @param input Input string to operate the trim on
     * @param find Optional other than default " " to search/trim on
     * @return Returns trimmed string or same string if there was nothing to trim
     */
    std::string StringHelpers::trim_string(const std::string &input, const std::string &find)
    {
        const size_t first = input.find_first_not_of(find);
        if (first == std::string::npos)
        {
            return input;
        }
        const size_t last = input.find_last_not_of(find);

        return input.substr(first, (last - first + 1));
    }

    /**
     * @brief Get (sub)string between two chars, for example [..string..]
     * @param input string to search in
     * @param start start character (excluding)
     * @param end end character (excluding)
     * @return returns string between start and end character or empty string in case of failure
     */
    std::string StringHelpers::get_string_between_two_chars(const std::string &input, const char start, const char end)
    {
        const size_t sstart = input.find(start);
        const size_t send = input.find(end, sstart + 1);

        if ((sstart != std::string::npos) &&
                (send != std::string::npos) &&
                (sstart != send + 1))
        {
            return input.substr(sstart + 1, (send - sstart) - 1);
        }

        return "";
    }

    /**
     * @brief Split a string by split_char and only return two parts, ignoring all following split_char
     * @param input input data to split on
     * @param split_char split character
     * @return vector of max two strings, vector of one string if split_char not found
     */
    std::vector<std::string> StringHelpers::split_string_once(const std::string &input, const char split_char)
    {
        bool split_found = false;
        std::vector<std::string> tmp;
        std::string tmp_string;

        for (const char c: input)
        {
            if (split_found)
            {
                tmp_string.push_back(c);
            }
            else
            {
                if (c == split_char)
                {
                    split_found = true;
                    tmp.push_back(tmp_string);
                    tmp_string.clear();
                }
                else
                {
                    tmp_string.push_back(c);
                }
            }
        }

        if (!tmp_string.empty())
        {
            tmp.push_back(tmp_string);
        }

        return tmp;
    }

}
