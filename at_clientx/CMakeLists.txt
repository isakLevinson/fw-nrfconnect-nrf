#
# Copyright (c) 2018 Nordic Semiconductor
#
# SPDX-License-Identifier: LicenseRef-BSD-5-Clause-Nordic
#

cmake_minimum_required(VERSION 3.8.2)

include($ENV{ZEPHYR_BASE}/cmake/app/boilerplate.cmake NO_POLICY_SCOPE)
project(NONE)

include_directories(inc)
include_directories(../services)
include_directories(../dbgterm)

target_sources(app PRIVATE "src/main.c")

file(GLOB services "../services/*.h" "../services/*.c")
file(GLOB dbgterm "../dbgterm/*.h" "../dbgterm/*.c")

add_library(services ${services})
add_library(dbgterm  ${dbgterm})


#file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.c")
#add_executable(main ${SOURCES})