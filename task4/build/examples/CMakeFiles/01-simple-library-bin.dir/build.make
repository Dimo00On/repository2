# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dima/playground/task4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dima/playground/task4/build

# Include any dependencies generated for this target.
include examples/CMakeFiles/01-simple-library-bin.dir/depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/01-simple-library-bin.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/01-simple-library-bin.dir/flags.make

examples/CMakeFiles/01-simple-library-bin.dir/01-main.cpp.o: examples/CMakeFiles/01-simple-library-bin.dir/flags.make
examples/CMakeFiles/01-simple-library-bin.dir/01-main.cpp.o: ../examples/01-main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dima/playground/task4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/CMakeFiles/01-simple-library-bin.dir/01-main.cpp.o"
	cd /home/dima/playground/task4/build/examples && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/01-simple-library-bin.dir/01-main.cpp.o -c /home/dima/playground/task4/examples/01-main.cpp

examples/CMakeFiles/01-simple-library-bin.dir/01-main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/01-simple-library-bin.dir/01-main.cpp.i"
	cd /home/dima/playground/task4/build/examples && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dima/playground/task4/examples/01-main.cpp > CMakeFiles/01-simple-library-bin.dir/01-main.cpp.i

examples/CMakeFiles/01-simple-library-bin.dir/01-main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/01-simple-library-bin.dir/01-main.cpp.s"
	cd /home/dima/playground/task4/build/examples && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dima/playground/task4/examples/01-main.cpp -o CMakeFiles/01-simple-library-bin.dir/01-main.cpp.s

# Object files for target 01-simple-library-bin
01__simple__library__bin_OBJECTS = \
"CMakeFiles/01-simple-library-bin.dir/01-main.cpp.o"

# External object files for target 01-simple-library-bin
01__simple__library__bin_EXTERNAL_OBJECTS =

../bin/01-simple-library-bin: examples/CMakeFiles/01-simple-library-bin.dir/01-main.cpp.o
../bin/01-simple-library-bin: examples/CMakeFiles/01-simple-library-bin.dir/build.make
../bin/01-simple-library-bin: src/01-simple-library/lib01-simple-library.so
../bin/01-simple-library-bin: examples/CMakeFiles/01-simple-library-bin.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dima/playground/task4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/01-simple-library-bin"
	cd /home/dima/playground/task4/build/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/01-simple-library-bin.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/01-simple-library-bin.dir/build: ../bin/01-simple-library-bin

.PHONY : examples/CMakeFiles/01-simple-library-bin.dir/build

examples/CMakeFiles/01-simple-library-bin.dir/clean:
	cd /home/dima/playground/task4/build/examples && $(CMAKE_COMMAND) -P CMakeFiles/01-simple-library-bin.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/01-simple-library-bin.dir/clean

examples/CMakeFiles/01-simple-library-bin.dir/depend:
	cd /home/dima/playground/task4/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dima/playground/task4 /home/dima/playground/task4/examples /home/dima/playground/task4/build /home/dima/playground/task4/build/examples /home/dima/playground/task4/build/examples/CMakeFiles/01-simple-library-bin.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/01-simple-library-bin.dir/depend

