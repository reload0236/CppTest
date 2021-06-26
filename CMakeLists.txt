# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.5)

# Set the project name
project (CppTests)

# set the C++ standard to C++ 11
set(CMAKE_CXX_STANDARD 11)

file(GLOB ROOT_SOURCES Source/*.cpp)
file(GLOB TEST_HEADERS Include/Tests/*.h)
file(GLOB TEST_SOURCES Source/Tests/*.cpp)
file(GLOB SOURCES ${ROOT_SOURCES} ${TEST_HEADERS} ${TEST_SOURCES})

source_group("Source" FILES ${ROOT_SOURCES} )
# TODO The slash makes an issue on windows. 
source_group("Include/Tests" FILES ${TEST_HEADERS})
source_group("Source/Tests" FILES ${TEST_SOURCES})

# Add an executable with the above sources
add_executable(CppTests ${SOURCES})

# Set the directories that should be included in the build command for this target
# when running g++ these will be included as -I/directory/path/
target_include_directories(CppTests
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/Include
)
