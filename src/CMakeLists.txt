#/* This Source Code Form is subject to the terms of the JCZ-Automatisering License, v1.0. */
#/* For more information, see the LICENSE file in the toplevel directory of this archive or package. */
#/* Copyright 2020 - JCZ-Automatisering */

set(sources
        config.h
        config.cpp
        config_section.cpp
        config_section.h
        config_value.cpp
        config_value.h

        string_helpers.cpp
        string_helpers.h
    )

add_library(jczconfig ${sources})
target_include_directories(jczconfig INTERFACE PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
