# start with Alpine-3.12.1
FROM alpine:3.12.1

# install base compiler and build deps
RUN apk add --update --no-cache \
    build-base \
    cmake \
    doxygen \
    graphviz \
    ttf-freefont \
    bash \
    wget \
    gtest \
    gtest-dev \
    cppcheck \
    ccache \
    git \
    python3 \
    npm \
    gdb \
    strace \
    ltrace \
    lsof \
    valgrind \
    py-lxml \
    py-pip && \
    pip install gcovr==4.2

# make sure /bin/sh is bash
RUN ln -sf /bin/bash /bin/sh
