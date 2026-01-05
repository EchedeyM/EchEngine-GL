cmake_minimum_required(VERSION 3.20)

project(EchEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(EchEngine
    src/main.cpp
    src/Core/Application.cpp
)