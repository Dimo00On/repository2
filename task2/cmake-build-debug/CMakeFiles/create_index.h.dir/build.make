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

# Utility rule file for create_index.h.

# Include any custom commands dependencies for this target.
include CMakeFiles/create_index.h.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/create_index.h.dir/progress.make

CMakeFiles/create_index.h:
	/home/dima/Docs/clion/bin/cmake/linux/bin/cmake python3 A/preparing.py

create_index.h: CMakeFiles/create_index.h
create_index.h: CMakeFiles/create_index.h.dir/build.make
.PHONY : create_index.h

# Rule to build all files generated by this target.
CMakeFiles/create_index.h.dir/build: create_index.h
.PHONY : CMakeFiles/create_index.h.dir/build

CMakeFiles/create_index.h.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/create_index.h.dir/cmake_clean.cmake
.PHONY : CMakeFiles/create_index.h.dir/clean

CMakeFiles/create_index.h.dir/depend:
	cd /home/dima/playground/task2/project/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dima/playground/task2/project /home/dima/playground/task2/project /home/dima/playground/task2/project/cmake-build-debug /home/dima/playground/task2/project/cmake-build-debug /home/dima/playground/task2/project/cmake-build-debug/CMakeFiles/create_index.h.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/create_index.h.dir/depend

