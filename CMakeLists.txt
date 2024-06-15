
cmake_minimum_required(VERSION 3.27)
project(StarWar)

set(CMAKE_CXX_STANDARD 17)

# Find the packages
find_package(GLEW REQUIRED)
find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)

# Add the path to the GLFW headers
include_directories("/usr/include/GLFW")

# Set the path to the GLUT library
set(CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu/")

# Define the source files
set(SOURCE_FILES main.cpp
        lib/getBMP.cpp
        Textures/Texture.h
        Textures/Texture.h
        Textures/Texture.cpp
        SolarSystem/Planet.h
        Textures/stb_image.h
)

# Add the path to the GLUT library
link_directories(/usr/lib/x86_64-linux-gnu/)

# Define the executable
add_executable(StarWar ${SOURCE_FILES}
        Textures/Texture.cpp)

# Link against the GLFW, GLEW, GLUT, and OpenGL libraries

target_link_libraries(StarWar glfw ${GLEW_LIBRARIES} ${GLUT_LIBRARIES} ${OPENGL_LIBRARIES})

# Include the GLEW, GLUT, and OpenGL directories
include_directories(${GLEW_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIR})
