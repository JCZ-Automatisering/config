#/* This Source Code Form is subject to the terms of the JCZ-Automatisering License, v1.0. */
#/* For more information, see the LICENSE file in the toplevel directory of this archive or package. */
#/* Copyright 2020 - JCZ-Automatisering */

set(libs
        jczconfig
        gtest
        gtest_main
    )

# function to add executables as test
#   the function should be called with two arguments:
#       <name-of-the-executable>
#       <sources-of-the-executable>
function(my_test exe_name exe_sources)
    add_executable(${exe_name} ${exe_sources})
    target_link_libraries(${exe_name} ${libs})

    message("Added executable:      ${exe_name}")
    foreach(item ${exe_sources})
        message("  src                  ${item}")
    endforeach()

    add_test(NAME ${exe_name} COMMAND ${exe_name} "--gtest_output=xml:test_${exe_name}.xml")
endfunction()

my_test(config_section_test config_section_test.cpp)
my_test(config_test config_test.cpp)
