# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/282/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /snap/clion/282/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mohamed/Graphics_project/StarWar

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mohamed/Graphics_project/StarWar/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/StarWar.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/StarWar.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/StarWar.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/StarWar.dir/flags.make

CMakeFiles/StarWar.dir/main.cpp.o: CMakeFiles/StarWar.dir/flags.make
CMakeFiles/StarWar.dir/main.cpp.o: /home/mohamed/Graphics_project/StarWar/main.cpp
CMakeFiles/StarWar.dir/main.cpp.o: CMakeFiles/StarWar.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mohamed/Graphics_project/StarWar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/StarWar.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/StarWar.dir/main.cpp.o -MF CMakeFiles/StarWar.dir/main.cpp.o.d -o CMakeFiles/StarWar.dir/main.cpp.o -c /home/mohamed/Graphics_project/StarWar/main.cpp

CMakeFiles/StarWar.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/StarWar.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mohamed/Graphics_project/StarWar/main.cpp > CMakeFiles/StarWar.dir/main.cpp.i

CMakeFiles/StarWar.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/StarWar.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mohamed/Graphics_project/StarWar/main.cpp -o CMakeFiles/StarWar.dir/main.cpp.s

CMakeFiles/StarWar.dir/lib/getBMP.cpp.o: CMakeFiles/StarWar.dir/flags.make
CMakeFiles/StarWar.dir/lib/getBMP.cpp.o: /home/mohamed/Graphics_project/StarWar/lib/getBMP.cpp
CMakeFiles/StarWar.dir/lib/getBMP.cpp.o: CMakeFiles/StarWar.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mohamed/Graphics_project/StarWar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/StarWar.dir/lib/getBMP.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/StarWar.dir/lib/getBMP.cpp.o -MF CMakeFiles/StarWar.dir/lib/getBMP.cpp.o.d -o CMakeFiles/StarWar.dir/lib/getBMP.cpp.o -c /home/mohamed/Graphics_project/StarWar/lib/getBMP.cpp

CMakeFiles/StarWar.dir/lib/getBMP.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/StarWar.dir/lib/getBMP.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mohamed/Graphics_project/StarWar/lib/getBMP.cpp > CMakeFiles/StarWar.dir/lib/getBMP.cpp.i

CMakeFiles/StarWar.dir/lib/getBMP.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/StarWar.dir/lib/getBMP.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mohamed/Graphics_project/StarWar/lib/getBMP.cpp -o CMakeFiles/StarWar.dir/lib/getBMP.cpp.s

CMakeFiles/StarWar.dir/Textures/Texture.cpp.o: CMakeFiles/StarWar.dir/flags.make
CMakeFiles/StarWar.dir/Textures/Texture.cpp.o: /home/mohamed/Graphics_project/StarWar/Textures/Texture.cpp
CMakeFiles/StarWar.dir/Textures/Texture.cpp.o: CMakeFiles/StarWar.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mohamed/Graphics_project/StarWar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/StarWar.dir/Textures/Texture.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/StarWar.dir/Textures/Texture.cpp.o -MF CMakeFiles/StarWar.dir/Textures/Texture.cpp.o.d -o CMakeFiles/StarWar.dir/Textures/Texture.cpp.o -c /home/mohamed/Graphics_project/StarWar/Textures/Texture.cpp

CMakeFiles/StarWar.dir/Textures/Texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/StarWar.dir/Textures/Texture.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mohamed/Graphics_project/StarWar/Textures/Texture.cpp > CMakeFiles/StarWar.dir/Textures/Texture.cpp.i

CMakeFiles/StarWar.dir/Textures/Texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/StarWar.dir/Textures/Texture.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mohamed/Graphics_project/StarWar/Textures/Texture.cpp -o CMakeFiles/StarWar.dir/Textures/Texture.cpp.s

# Object files for target StarWar
StarWar_OBJECTS = \
"CMakeFiles/StarWar.dir/main.cpp.o" \
"CMakeFiles/StarWar.dir/lib/getBMP.cpp.o" \
"CMakeFiles/StarWar.dir/Textures/Texture.cpp.o"

# External object files for target StarWar
StarWar_EXTERNAL_OBJECTS =

StarWar: CMakeFiles/StarWar.dir/main.cpp.o
StarWar: CMakeFiles/StarWar.dir/lib/getBMP.cpp.o
StarWar: CMakeFiles/StarWar.dir/Textures/Texture.cpp.o
StarWar: CMakeFiles/StarWar.dir/build.make
StarWar: /usr/lib/x86_64-linux-gnu/libGLEW.so
StarWar: /usr/lib/x86_64-linux-gnu/libglut.so
StarWar: /usr/lib/x86_64-linux-gnu/libXi.so
StarWar: /usr/lib/x86_64-linux-gnu/libOpenGL.so
StarWar: /usr/lib/x86_64-linux-gnu/libGLX.so
StarWar: /usr/lib/x86_64-linux-gnu/libGLU.so
StarWar: CMakeFiles/StarWar.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/mohamed/Graphics_project/StarWar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable StarWar"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/StarWar.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/StarWar.dir/build: StarWar
.PHONY : CMakeFiles/StarWar.dir/build

CMakeFiles/StarWar.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/StarWar.dir/cmake_clean.cmake
.PHONY : CMakeFiles/StarWar.dir/clean

CMakeFiles/StarWar.dir/depend:
	cd /home/mohamed/Graphics_project/StarWar/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mohamed/Graphics_project/StarWar /home/mohamed/Graphics_project/StarWar /home/mohamed/Graphics_project/StarWar/cmake-build-debug /home/mohamed/Graphics_project/StarWar/cmake-build-debug /home/mohamed/Graphics_project/StarWar/cmake-build-debug/CMakeFiles/StarWar.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/StarWar.dir/depend

