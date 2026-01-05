cmake_minimum_required(VERSION 3.20)
project(EchEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Force dynamic runtime in MSVC
if(MSVC)
    foreach(flag_var
            CMAKE_C_FLAGS CMAKE_C_FLAGS_DEBUG CMAKE_C_FLAGS_RELEASE
            CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE)
        string(REPLACE "/MT" "/MD" ${flag_var} "${${flag_var}}")
        string(REPLACE "/MTd" "/MDd" ${flag_var} "${${flag_var}}")
    endforeach()
endif()

# GLAD
include_directories(src/Dependencies/GLAD/include)
add_library(GLAD_OBJ OBJECT src/Dependencies/GLAD/src/glad.c)
set_target_properties(GLAD_OBJ PROPERTIES LINKER_LANGUAGE C)
if(MSVC)
    set_target_properties(GLAD_OBJ PROPERTIES MSVC_RUNTIME_LIBRARY "MultiThreadedDLL")
endif()

# GLFW
set(GLFW_USE_STATIC_CRT OFF CACHE BOOL "" FORCE)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDLL" CACHE STRING "MSVC runtime library" FORCE)
add_subdirectory(src/Dependencies/GLFW)

if(MSVC)
    set_target_properties(glfw PROPERTIES MSVC_RUNTIME_LIBRARY "MultiThreadedDLL")
endif()

# Ejecutable
add_executable(EchEngine
    src/main.cpp
    src/Core/Application.cpp
)

# Link libraries
target_link_libraries(EchEngine PRIVATE 
    $<TARGET_OBJECTS:GLAD_OBJ>
    glfw
    opengl32
    legacy_stdio_definitions
)

if(MSVC)
    set_target_properties(EchEngine PROPERTIES LINK_FLAGS "/NODEFAULTLIB:LIBCMT")
endif()
