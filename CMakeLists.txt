cmake_minimum_required(VERSION 4.1)

project(Project_3 VERSION 1.0
        DESCRIPTION "Corner Grocer Item Tracking Program"
        LANGUAGES CXX)

# Use C++20 standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(Project_3
        main.cpp
)