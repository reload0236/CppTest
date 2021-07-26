# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.5)

# Set the project name
project (CppTests)

# set the C++ standard to C++ 11
set(CMAKE_CXX_STANDARD 11)

# set a project version
set (CPP_TESTS_VERTION_MAJOR 0)
set (CPP_TESTS_VERTION_MINOR 0)
set (CPP_TESTS_VERTION_PATCH 1)
set (CPP_TESTS_VERTION_BUILD 1)
set (CPP_TESTS_VERTION "${CPP_TESTS_VERTION_MAJOR}.${CPP_TESTS_VERTION_MINOR}.${CPP_TESTS_VERTION_PATCH}.${CPP_TESTS_VERTION_BUILD}")

# Call configure files on Version.h.in to set the version.
# Uses the standard ${VARIABLE} syntax in the file
configure_file(Version.h.in ${CMAKE_CURRENT_BINARY_DIR}/Include/Version.h)

file(GLOB ROOT_SOURCES Source/*.cpp)
file(GLOB TEST_HEADERS Include/Tests/*.h)
file(GLOB TEST_SOURCES Source/Tests/*.cpp)
file(GLOB SOURCES ${ROOT_SOURCES} ${TEST_HEADERS} ${TEST_SOURCES})

source_group("Source" FILES ${ROOT_SOURCES} )
# TODO Should find a better way to differenciate path seperator on different platforms.
if (WIN32)
    source_group("Include\\Tests" FILES ${TEST_HEADERS})
    source_group("Source\\Tests" FILES ${TEST_SOURCES})
else ()
    source_group("Include/Tests" FILES ${TEST_HEADERS})
    source_group("Source/Tests" FILES ${TEST_SOURCES})
endif ()

# Add an executable with the above sources
add_executable(CppTests ${SOURCES})

# Set the directories that should be included in the build command for this target
# when running g++ these will be included as -I/directory/path/
target_include_directories(CppTests
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/Include
        ${CMAKE_CURRENT_BINARY_DIR}/Include
)
