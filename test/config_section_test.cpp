/* This Source Code Form is subject to the terms of the JCZ-Automatisering License, v1.0. */
/* For more information, see the LICENSE file in the toplevel directory of this archive or package. */
/* Copyright 2020 - JCZ-Automatisering */

#include <gtest/gtest.h>
#include "config_section.h"

#include <string.h>

#ifdef RELEASE_BUILD
#define TEST_NAME config_section_release
#else
#define TEST_NAME config_section
#endif

using namespace jczconfig;

TEST(TEST_NAME, init)
{
    ConfigSection s("");
    EXPECT_EQ(s.get_name(), "");
    EXPECT_EQ(s.to_string(), "[]\n\n");
    EXPECT_FALSE(s.has_member(""));
    EXPECT_FALSE(s.has_member("bla"));
    EXPECT_FALSE(s.has_members({""}));
    EXPECT_FALSE(s.has_members({"bla"}));
    EXPECT_FALSE(s.has_members({"", "bla"}));
}

TEST(TEST_NAME, with_one_member)
{
    ConfigSection s("test");
    ConfigValue cv;
    cv.key = "key";
    cv.value = "value";
    s.section_members.push_back(cv);
    EXPECT_TRUE(s.has_member("key"));
    EXPECT_TRUE(s.has_members({"key"}));
    EXPECT_FALSE(s.has_members({"key", "value"}));
    EXPECT_EQ(s.get_member("key"), "value");
    EXPECT_EQ(s.get_member("value"), "");   /* does not exist, should return an empty string */
    EXPECT_EQ(s.to_string(), "[test]\nkey=value\n\n");
}
