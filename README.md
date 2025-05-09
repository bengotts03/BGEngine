# BGEngine

A modern C++ game engine loosely based off of the Hazel engine youtube series.

## Prerequisites

- CMake 3.16 or higher
- C++17 compatible compiler
- vcpkg package manager

## Setup

### Installing vcpkg

```bash
# Clone vcpkg
git clone https://github.com/Microsoft/vcpkg.git
cd vcpkg

# Build vcpkg
./bootstrap-vcpkg.sh  # For Linux/macOS
# or
.\bootstrap-vcpkg.bat  # For Windows

# Add the environment variable for CMake to find vcpkg
# For Linux/macOS
export VCPKG_ROOT=/path/to/vcpkg
# For Windows (PowerShell)
$env:VCPKG_ROOT="C:\path\to\vcpkg"
```

### Building with CMake

```bash
# Clone the repository
git clone https://github.com/yourusername/BGEngine.git
cd BGEngine

# Configure and build
cmake -B build
cmake --build build
```

### Opening in CLion

1. Open CLion
2. Select "Open" and navigate to the BGEngine directory
3. CLion should automatically detect the CMakeLists.txt file
4. Make sure to set the VCPKG_ROOT environment variable in CLion:
   - Go to Settings → Build, Execution, Deployment → CMake
   - Add `VCPKG_ROOT=C:\path\to\vcpkg` to the Environment field

## Project Structure

- **BGEngine**: Core engine library
- **ExampleGame**: Example application using the engine

## Building and Running

After configuring the project with CMake, you can build and run the ExampleGame application:

```bash
# Build
cmake --build build

# Run
./build/bin/ExampleGame
```

## License

This project is licensed under the MIT License - see the LICENSE file for details.
