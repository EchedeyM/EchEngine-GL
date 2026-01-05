# EchEngine-GL

EchEngine is a minimal graphics engine built to learn modern rendering APIs and engine development patterns. Currently implemented with OpenGL 3.3+ on Windows using MSVC.

## Features
- Modern C++20 implementation
- OpenGL 3.3+ Core Profile rendering
- GLFW window management and input handling
- GLAD OpenGL loader

## Goals
- Learn engine development fundamentals
- Build a robust OpenGL renderer
- Establish a solid architecture for future graphics backends
- Later port the engine to Vulkan

## Prerequisites

- **OS**: Windows 10 or later
- **Compiler**: MSVC 2022 (C++20 support required)
- **Build System**: CMake 3.20+
- **Dependencies**: Included as git submodules
  - GLFW 3.x (window & input management)
  - GLAD (OpenGL loader)

## Building

### Configure
```bash
cd build
cmake .. -G "Visual Studio 17 2022"
```

### Compile
```bash
# Debug
cmake --build . --config Debug

# Release
cmake --build . --config Release
```

### Run
```bash
./Debug/EchEngine.exe    # Debug build
./Release/EchEngine.exe  # Release build
```

## Project Structure
```
src/
├── main.cpp                    # Entry point
├── Core/
│   ├── Application.h           # Main application class
│   └── Application.cpp
└── Dependencies/
    ├── GLAD/                   # OpenGL function loader
    └── GLFW/                   # Window & input library
```

## Notes

### Runtime Library Configuration
This project uses **dynamic MSVC runtime library** (`/MD` and `/MDd`) to ensure compatibility between all components (GLAD, GLFW, and the main application). All dependencies are built with consistent runtime settings.

