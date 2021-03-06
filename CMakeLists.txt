#/* This Source Code Form is subject to the terms of the JCZ-Automatisering License, v1.0. */
#/* For more information, see the LICENSE file in the toplevel directory of this archive or package. */
#/* Copyright 2020 - JCZ-Automatisering */

cmake_minimum_required (VERSION 3.0)
project(jczconfig LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)

enable_testing()

add_subdirectory(src)

if (NOT DEFINED JCZCONFIG_NO_TESTS)
    add_subdirectory(test)
endif()

set(non_sources
        .gitignore
        README.md
        LICENSE
        Dockerfile
        Jenkinsfile
        autobuild.ini
        build_settings.sh
        cppcheck.sh
        coverage.sh
        Doxyfile
    )

add_executable(non_sources_config src/dummy.cpp ${non_sources})
set_target_properties(non_sources_config PROPERTIES EXCLUDE_FROM_ALL TRUE)

