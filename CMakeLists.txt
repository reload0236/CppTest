# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.5)

# Set the project name
project (CppTests)

# set the C++ standard to C++ 11
set(CMAKE_CXX_STANDARD 11)

# Create a sources variable with a link to all cpp files to compile
# Don't kwnow how to match with wildcard.
set(SOURCES
    Source/Main.cpp
)

# Add an executable with the above sources
add_executable(CppTests ${SOURCES})

# Set the directories that should be included in the build command for this target
# when running g++ these will be included as -I/directory/path/
target_include_directories(CppTests
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/Source
)
