/* This Source Code Form is subject to the terms of the JCZ-Automatisering License, v1.0. */
/* For more information, see the LICENSE file in the toplevel directory of this archive or package. */
/* Copyright 2020 - JCZ-Automatisering */

#include <gtest/gtest.h>
#include "config.h"

#include <string.h>
#include <vector>
#include "string_helpers.h"

#ifdef RELEASE_BUILD
#define TEST_NAME config_release
#else
#define TEST_NAME config
#endif

using namespace jczconfig;

TEST(TEST_NAME, init)
{
    Config c;   /* empty config */

    EXPECT_FALSE(c.status());
    //EXPECT_EQ(c.get_ini_file_location(), "");
    EXPECT_FALSE(c.has_section(""));
    ConfigSection sec = c.get_section("");
    EXPECT_EQ(sec.to_string(), "[]\n\n");
    EXPECT_FALSE(c.load(""));

    std::vector<ConfigSection> sections = c.get_sections();
    EXPECT_TRUE(sections.empty());
    EXPECT_FALSE(c.load("\n"));
    EXPECT_FALSE(c.status());
}

const std::string invalid_ini = "thisisno=yes\navalidinifile\n\n";

const std::string simple_ini =
        "[main]\n"
        "key1=value1\n"
        "key2=value2\n\n";

TEST(TEST_NAME, simple)
{
    Config c;

    EXPECT_FALSE(c.load(invalid_ini));
    EXPECT_FALSE(c.status());
    EXPECT_TRUE(c.load(simple_ini));
    EXPECT_TRUE(c.status());
    EXPECT_TRUE(c.has_section("main"));
    EXPECT_FALSE(c.has_section("general"));
    std::vector<ConfigSection> sections = c.get_sections();
    EXPECT_EQ(sections.size(), 1);
    ConfigSection section = c.get_section("main");
    EXPECT_EQ(section.get_name(), "main");

    const std::string value1 = c.get_section_member("main", "key1");
    EXPECT_EQ(value1, "value1");
    const std::string value2 = c.get_section_member("main", "key2");
    EXPECT_EQ(value2, "value2");
    const std::string value3 = c.get_section_member("main", "key3");
    EXPECT_EQ(value3, "");

    EXPECT_EQ(c.get_section_member("no", "yes", "default"), "default");

    const std::string to_string = c.to_string();
    EXPECT_EQ(to_string, simple_ini);

    c.clear();
    EXPECT_FALSE(c.status());
}

/* todo: */
const std::string complexer_ini =
        "[]\n"
        "[section1]\n"
        "key1=value1\n"
        "key2=valkue2\n"
        "#[section2]\n"
        "[section3]\n"
        "key1=value3\n"
        "key2=value4\n"
        "nonkey\n";

TEST(TEST_NAME, complex)
{
    Config c;

    EXPECT_TRUE(c.load(complexer_ini));

    EXPECT_TRUE(c.has_section("section1"));
    EXPECT_FALSE(c.has_section("section2"));
    EXPECT_TRUE(c.has_section("section3"));

    const ConfigSection s3 = c.get_section("section3");
    EXPECT_TRUE(s3.has_members({"key1", "key2"}));
    EXPECT_FALSE(s3.has_member("nonkey"));
}
