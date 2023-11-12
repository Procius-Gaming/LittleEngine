# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nesmy/Playground/LittleEngine/SandBox

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nesmy/Playground/LittleEngine/build

# Include any dependencies generated for this target.
include CMakeFiles/SandBox.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SandBox.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SandBox.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SandBox.dir/flags.make

CMakeFiles/SandBox.dir/src/SandBoxApp.cpp.o: CMakeFiles/SandBox.dir/flags.make
CMakeFiles/SandBox.dir/src/SandBoxApp.cpp.o: /home/nesmy/Playground/LittleEngine/SandBox/src/SandBoxApp.cpp
CMakeFiles/SandBox.dir/src/SandBoxApp.cpp.o: CMakeFiles/SandBox.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nesmy/Playground/LittleEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SandBox.dir/src/SandBoxApp.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SandBox.dir/src/SandBoxApp.cpp.o -MF CMakeFiles/SandBox.dir/src/SandBoxApp.cpp.o.d -o CMakeFiles/SandBox.dir/src/SandBoxApp.cpp.o -c /home/nesmy/Playground/LittleEngine/SandBox/src/SandBoxApp.cpp

CMakeFiles/SandBox.dir/src/SandBoxApp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SandBox.dir/src/SandBoxApp.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nesmy/Playground/LittleEngine/SandBox/src/SandBoxApp.cpp > CMakeFiles/SandBox.dir/src/SandBoxApp.cpp.i

CMakeFiles/SandBox.dir/src/SandBoxApp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SandBox.dir/src/SandBoxApp.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nesmy/Playground/LittleEngine/SandBox/src/SandBoxApp.cpp -o CMakeFiles/SandBox.dir/src/SandBoxApp.cpp.s

# Object files for target SandBox
SandBox_OBJECTS = \
"CMakeFiles/SandBox.dir/src/SandBoxApp.cpp.o"

# External object files for target SandBox
SandBox_EXTERNAL_OBJECTS =

SandBox: CMakeFiles/SandBox.dir/src/SandBoxApp.cpp.o
SandBox: CMakeFiles/SandBox.dir/build.make
SandBox: Little/libLittle.so
SandBox: Little/glad/libglad.a
SandBox: Little/glfw/src/libglfw3.a
SandBox: /usr/lib/x86_64-linux-gnu/librt.a
SandBox: /usr/lib/x86_64-linux-gnu/libm.so
SandBox: CMakeFiles/SandBox.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nesmy/Playground/LittleEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SandBox"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SandBox.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SandBox.dir/build: SandBox
.PHONY : CMakeFiles/SandBox.dir/build

CMakeFiles/SandBox.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SandBox.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SandBox.dir/clean

CMakeFiles/SandBox.dir/depend:
	cd /home/nesmy/Playground/LittleEngine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nesmy/Playground/LittleEngine/SandBox /home/nesmy/Playground/LittleEngine/SandBox /home/nesmy/Playground/LittleEngine/build /home/nesmy/Playground/LittleEngine/build /home/nesmy/Playground/LittleEngine/build/CMakeFiles/SandBox.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SandBox.dir/depend

