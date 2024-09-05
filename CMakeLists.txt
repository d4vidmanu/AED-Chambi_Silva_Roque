cmake_minimum_required(VERSION 3.29)
project(AED_Chambi_Silva_Roque)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(.)

# Add main executable (without test files)
add_executable(AED_Chambi_Silva_Roque
        ForwardList/ForwardList.cpp
        ForwardList/ForwardList.h
        main.cpp
)

# GoogleTest requires at least C++14
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Add test executable
add_executable(ForwardListTest
        ForwardList/ForwardList.cpp
        ForwardList/ForwardList.h
        ForwardList/Tests/ForwardListTest.cpp
        ForwardList/Tests/testing1.cpp
        ForwardList/Tests/testing2.cpp
        ForwardList/Tests/testing3.cpp
        ForwardList/Tests/testing4.cpp
)

# Link the GoogleTest libraries with the test executable
target_link_libraries(ForwardListTest gtest gtest_main)