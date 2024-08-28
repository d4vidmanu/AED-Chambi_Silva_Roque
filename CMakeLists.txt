cmake_minimum_required(VERSION 3.29)
project(AED_Chambi_Silva_Roque)

set(CMAKE_CXX_STANDARD 14)

include_directories("Forward List")

add_executable(AED_Chambi_Silva_Roque
    "Forward List/ForwardList.cpp"
    "Forward List/ForwardList.h"
        main.cpp)
