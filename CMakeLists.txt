cmake_minimum_required(VERSION 3.16)

project(MotionCore LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Our MotionCore library
add_library(motioncore
    src/trajectory.cpp
    src/measurementBuffer.h
)

target_include_directories(motioncore PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Download GoogleTest
include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.18.0
    GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(googletest)

# Build the test executable
add_executable(motioncore_tests
    tests/trajTest.cpp
    tests/measurementBufferTest.cpp
)

# add_executable(practice
# )

target_link_libraries(motioncore_tests PRIVATE
    motioncore
    GTest::gtest_main
)

# Register individual GoogleTest tests with CTest
enable_testing()

include(GoogleTest)

gtest_discover_tests(motioncore_tests)