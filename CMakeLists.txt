cmake_minimum_required(VERSION 3.10)

project(iori_game_engine)

set(CMAKE_CXX_STANDARD 20)

//------------------------Optimization Level------------------------

// GCC/Clang
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
endif()

// MSVC
if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /O2")
endif()

// icpx (or Intel)
if(CMAKE_CXX_COMPILER_ID MATCHES "Intel")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
endif()

//------------------------Warning Level------------------------

// GCC
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Wshadow -Wconversion -Wsign-conversion -Wold-style-cast \
                         -Wcast-align -Wunused -Wnon-virtual-dtor -Weffc++")
endif()