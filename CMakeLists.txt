cmake_minimum_required(VERSION 3.10)

project(iori_game_engine)

set(CMAKE_CXX_STANDARD 20)

#------------------------Optimization Level------------------------

# GCC/Clang/Intel
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU|Intel")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
endif()

# MSVC
if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /O2")
endif()

#------------------------Warning Level------------------------

# GCC
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Wshadow -Wconversion -Wsign-conversion -Wold-style-cast \
                         -Wcast-align -Wunused -Wnon-virtual-dtor -Weffc++")
endif()

# Clang/Intel
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|Intel")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Wshadow -Wconversion -Wsign-conversion -Wold-style-cast \
                         -Wcast-align -Wunused -Wnon-virtual-dtor -Weffc++")
endif()

# MSVC
if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /WX")
endif()

#------------------------Debugging Level------------------------
# GCC/Clang/
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g3 -ggdb")
endif()

# MSVC
if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zi")
endif()

#------------------------Profiling flags------------------------
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pg -fbranch-probabilities -fprofile-generate")
endif()

# MSVC
if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /PROFILE")
endif()

# Actual project
set(SOURCES
    src/main.cpp
)

# Include directory
include_directories(
    include
)

# Add the executable target
add_executable(${PROJECT_NAME} ${SOURCES})

# Link libraries