cmake_minimum_required(VERSION 3.25)
project(untitled55)

set(CMAKE_CXX_STANDARD 17)

add_executable(StarWar main.cpp)  # Ensure to include all relevant source files

# Link against the necessary libraries
target_link_libraries(StarWar -lglew32 -lopengl32 -lfreeglut -lglu32)
