cmake_minimum_required(VERSION 3.12)

project(leetcode LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

option(INSTALL_GTEST OFF)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(googletest)
include_directories(${gtest_build_include_dirs})

aux_source_directory(. SRC)
enable_testing()
include(GoogleTest)

foreach(case ${SRC})
    get_filename_component(case_ ${case} NAME_WE)
    add_executable(${case_} ${case})
    target_link_libraries(${case_} gtest_main)
    gtest_discover_tests(${case_})
endforeach()

add_subdirectory(graph)