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

# Include any dependencies generated for this target.
include CMakeFiles/CTest.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/CTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CTest.dir/flags.make

CMakeFiles/CTest.dir/C/main_test.cpp.o: CMakeFiles/CTest.dir/flags.make
CMakeFiles/CTest.dir/C/main_test.cpp.o: ../C/main_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dima/playground/task2/project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CTest.dir/C/main_test.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CTest.dir/C/main_test.cpp.o -c /home/dima/playground/task2/project/C/main_test.cpp

CMakeFiles/CTest.dir/C/main_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CTest.dir/C/main_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dima/playground/task2/project/C/main_test.cpp > CMakeFiles/CTest.dir/C/main_test.cpp.i

CMakeFiles/CTest.dir/C/main_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CTest.dir/C/main_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dima/playground/task2/project/C/main_test.cpp -o CMakeFiles/CTest.dir/C/main_test.cpp.s

CMakeFiles/CTest.dir/C/othercppfile.cpp.o: CMakeFiles/CTest.dir/flags.make
CMakeFiles/CTest.dir/C/othercppfile.cpp.o: ../C/othercppfile.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dima/playground/task2/project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CTest.dir/C/othercppfile.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CTest.dir/C/othercppfile.cpp.o -c /home/dima/playground/task2/project/C/othercppfile.cpp

CMakeFiles/CTest.dir/C/othercppfile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CTest.dir/C/othercppfile.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dima/playground/task2/project/C/othercppfile.cpp > CMakeFiles/CTest.dir/C/othercppfile.cpp.i

CMakeFiles/CTest.dir/C/othercppfile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CTest.dir/C/othercppfile.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dima/playground/task2/project/C/othercppfile.cpp -o CMakeFiles/CTest.dir/C/othercppfile.cpp.s

# Object files for target CTest
CTest_OBJECTS = \
"CMakeFiles/CTest.dir/C/main_test.cpp.o" \
"CMakeFiles/CTest.dir/C/othercppfile.cpp.o"

# External object files for target CTest
CTest_EXTERNAL_OBJECTS =

../bin/CTest: CMakeFiles/CTest.dir/C/main_test.cpp.o
../bin/CTest: CMakeFiles/CTest.dir/C/othercppfile.cpp.o
../bin/CTest: CMakeFiles/CTest.dir/build.make
../bin/CTest: CMakeFiles/CTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dima/playground/task2/project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../bin/CTest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CTest.dir/build: ../bin/CTest
.PHONY : CMakeFiles/CTest.dir/build

CMakeFiles/CTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CTest.dir/clean

CMakeFiles/CTest.dir/depend:
	cd /home/dima/playground/task2/project/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dima/playground/task2/project /home/dima/playground/task2/project /home/dima/playground/task2/project/cmake-build-debug /home/dima/playground/task2/project/cmake-build-debug /home/dima/playground/task2/project/cmake-build-debug/CMakeFiles/CTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CTest.dir/depend

