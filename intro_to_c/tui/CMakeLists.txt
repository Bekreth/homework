cmake_minimum_required(VERSION 3.15)
project(tui C)

add_library(tui src/tui.c)
target_include_directories(tui PUBLIC include)

set_target_properties(tui PROPERTIES PUBLIC_HEADER "include/tui.h")
install(TARGETS tui)
