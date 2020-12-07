#!/bin/sh

export CC="ccache gcc"
export CXX="ccache g++"
export CXXFLAGS="-O0 -ggdb -fprofile-arcs -ftest-coverage"
export LDFLAGS="-lgcov"
