# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /home/dima/Docs/clion/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/dima/Docs/clion/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dima/playground/task2/project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dima/playground/task2/project/cmake-build-debug

# Utility rule file for need.

# Include any custom commands dependencies for this target.
include CMakeFiles/need.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/need.dir/progress.make

CMakeFiles/need: libNewLib.so

need: CMakeFiles/need
need: CMakeFiles/need.dir/build.make
.PHONY : need

# Rule to build all files generated by this target.
CMakeFiles/need.dir/build: need
.PHONY : CMakeFiles/need.dir/build

CMakeFiles/need.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/need.dir/cmake_clean.cmake
.PHONY : CMakeFiles/need.dir/clean

CMakeFiles/need.dir/depend:
	cd /home/dima/playground/task2/project/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dima/playground/task2/project /home/dima/playground/task2/project /home/dima/playground/task2/project/cmake-build-debug /home/dima/playground/task2/project/cmake-build-debug /home/dima/playground/task2/project/cmake-build-debug/CMakeFiles/need.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/need.dir/depend

