/* This Source Code Form is subject to the terms of the JCZ-Automatisering License, v1.0. */
/* For more information, see the LICENSE file in the toplevel directory of this archive or package. */
/* Copyright 2020 - JCZ-Automatisering */

#include <gtest/gtest.h>
#include "string_helpers.h"

#include <vector>
#include "string_helpers.h"

#ifdef RELEASE_BUILD
#define TEST_NAME string_helpers_release
#else
#define TEST_NAME string_helpers
#endif

using namespace jczconfig;

TEST(TEST_NAME, get_string_between_two_chars)
{
    const std::string input_string = "this is a 'test\" really.";
    std::string result = StringHelpers::get_string_between_two_chars(input_string, '\'', '\"');
    EXPECT_EQ(result, "test");
    result = StringHelpers::get_string_between_two_chars(input_string, 'x', 'y');
    EXPECT_TRUE(result.empty());
    result = StringHelpers::get_string_between_two_chars(input_string, '.', '.');
    EXPECT_TRUE(result.empty());
}
