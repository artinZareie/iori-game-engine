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

#------------------------Dependencies Setup------------------------
find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

set(IMGUI_SOURCES
    third_party/imgui/imgui.cpp
    third_party/imgui/imgui_demo.cpp
    third_party/imgui/imgui_draw.cpp
    third_party/imgui/imgui_tables.cpp
    third_party/imgui/imgui_widgets.cpp
    third_party/imgui/backends/imgui_impl_glfw.cpp
    third_party/imgui/backends/imgui_impl_opengl3.cpp
)

add_library(imgui
    ${IMGUI_SOURCES}
)

#------------------------Project Setup------------------------

# Actual project
set(SOURCES
    src/main.cpp
)

# Include directory
include_directories(
    include
    third_party/imgui
    third_party/imgui/backends
)

# Add the executable target
add_executable(${PROJECT_NAME} ${SOURCES})

# Link libraries
target_include_directories(${PROJECT_NAME} PRIVATE
    third_party/imgui
    third_party/imgui/backends
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    glfw
    GL
    imgui
)