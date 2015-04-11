cmake_minimum_required(VERSION 3.1)
project(Algorithms)

#Set CFLAGs
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fopenmp -O3")

#Set LFLAGs
set (CMAKE_EXE_LINKER_FLAGS -fopenmp )

#grab all files we need to compile
file(GLOB_RECURSE SRC
    "source/*/*.cpp"
    "source/*/*.h"
)

# compile all algorithms into the library
add_library( AlgorithmsLib ${SRC} )
target_include_directories (AlgorithmsLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCE_FILES source/main.cpp)
add_executable(Algorithms ${SOURCE_FILES})
target_link_libraries( Algorithms AlgorithmsLib )