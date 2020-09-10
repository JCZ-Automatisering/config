#/* This Source Code Form is subject to the terms of the JCZ-Automatisering License, v1.0. */
#/* For more information, see the LICENSE file in the toplevel directory of this archive or package. */
#/* Copyright 2020 - JCZ-Automatisering */

cmake_minimum_required (VERSION 3.0)
project(jczconfig LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)

enable_testing()

add_subdirectory(src)
add_subdirectory(test)

set(non_sources
        .gitignore
        README.md
        LICENSE
        Dockerfile
        Doxyfile
    )

add_executable(non_sources_config src/dummy.cpp ${non_sources})
set_target_properties(non_sources_config PROPERTIES EXCLUDE_FROM_ALL TRUE)

