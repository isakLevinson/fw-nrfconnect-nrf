#
# Copyright (c) 2018 Nordic Semiconductor
#
# SPDX-License-Identifier: LicenseRef-BSD-5-Clause-Nordic
#

cmake_minimum_required(VERSION 3.8.2)

include($ENV{ZEPHYR_BASE}/cmake/app/boilerplate.cmake NO_POLICY_SCOPE)
project(NONE)

include_directories(inc)
include_directories(src)
include_directories(../services)
include_directories(../dbgterm)

file(GLOB src "src/*.h" "src/*.c")
file(GLOB services "../services/*.h" "../services/*.c")
file(GLOB dbgterm "../dbgterm/*.h" "../dbgterm/*.c")

target_sources(app PRIVATE ${src})
target_sources(app PRIVATE ${services})
target_sources(app PRIVATE ${dbgterm})

#add_library(services STATIC ${services})
#add_library(dbgterm  STATIC ${dbgterm})


#file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.c")
#add_executable(main ${SOURCES})
