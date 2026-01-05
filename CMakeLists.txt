cmake_minimum_required(VERSION 3.20)

project(EchEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(EchEngine
    src/main.cpp
    src/Core/Application.cpp
)


# Include GLFW headers
include_directories(src/Dependencies/GLFW/include)

# Compile GLFW as part of the project
add_library(GLFW_LIB
    src/Dependencies/GLFW/src/context.c
    src/Dependencies/GLFW/src/init.c
    src/Dependencies/GLFW/src/input.c
    src/Dependencies/GLFW/src/monitor.c
    src/Dependencies/GLFW/src/window.c
    src/Dependencies/GLFW/src/vulkan.c # Optional
)

# Inclue GLAD headers
include_directories(src/Dependencies/GLAD/include)

# Compile GLAD as part of the project
add_library(GLAD_LIB
    src/Dependencies/GLAD/src/glad.c
)

# Link GLFW & GLAD to the main executable
target_link_libraries(EchEngine PRIVATE GLFW_LIB GLAD_LIB)
