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
CMAKE_SOURCE_DIR = /home/seb/Desktop/projects/digital_simulation_project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/seb/Desktop/projects/digital_simulation_project/build

# Include any dependencies generated for this target.
include src/CMakeFiles/include.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/include.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/include.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/include.dir/flags.make

src/CMakeFiles/include.dir/user.cpp.o: src/CMakeFiles/include.dir/flags.make
src/CMakeFiles/include.dir/user.cpp.o: ../src/user.cpp
src/CMakeFiles/include.dir/user.cpp.o: src/CMakeFiles/include.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/seb/Desktop/projects/digital_simulation_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/include.dir/user.cpp.o"
	cd /home/seb/Desktop/projects/digital_simulation_project/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/include.dir/user.cpp.o -MF CMakeFiles/include.dir/user.cpp.o.d -o CMakeFiles/include.dir/user.cpp.o -c /home/seb/Desktop/projects/digital_simulation_project/src/user.cpp

src/CMakeFiles/include.dir/user.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/include.dir/user.cpp.i"
	cd /home/seb/Desktop/projects/digital_simulation_project/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/seb/Desktop/projects/digital_simulation_project/src/user.cpp > CMakeFiles/include.dir/user.cpp.i

src/CMakeFiles/include.dir/user.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/include.dir/user.cpp.s"
	cd /home/seb/Desktop/projects/digital_simulation_project/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/seb/Desktop/projects/digital_simulation_project/src/user.cpp -o CMakeFiles/include.dir/user.cpp.s

src/CMakeFiles/include.dir/base.cpp.o: src/CMakeFiles/include.dir/flags.make
src/CMakeFiles/include.dir/base.cpp.o: ../src/base.cpp
src/CMakeFiles/include.dir/base.cpp.o: src/CMakeFiles/include.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/seb/Desktop/projects/digital_simulation_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/include.dir/base.cpp.o"
	cd /home/seb/Desktop/projects/digital_simulation_project/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/include.dir/base.cpp.o -MF CMakeFiles/include.dir/base.cpp.o.d -o CMakeFiles/include.dir/base.cpp.o -c /home/seb/Desktop/projects/digital_simulation_project/src/base.cpp

src/CMakeFiles/include.dir/base.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/include.dir/base.cpp.i"
	cd /home/seb/Desktop/projects/digital_simulation_project/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/seb/Desktop/projects/digital_simulation_project/src/base.cpp > CMakeFiles/include.dir/base.cpp.i

src/CMakeFiles/include.dir/base.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/include.dir/base.cpp.s"
	cd /home/seb/Desktop/projects/digital_simulation_project/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/seb/Desktop/projects/digital_simulation_project/src/base.cpp -o CMakeFiles/include.dir/base.cpp.s

# Object files for target include
include_OBJECTS = \
"CMakeFiles/include.dir/user.cpp.o" \
"CMakeFiles/include.dir/base.cpp.o"

# External object files for target include
include_EXTERNAL_OBJECTS =

src/libinclude.a: src/CMakeFiles/include.dir/user.cpp.o
src/libinclude.a: src/CMakeFiles/include.dir/base.cpp.o
src/libinclude.a: src/CMakeFiles/include.dir/build.make
src/libinclude.a: src/CMakeFiles/include.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/seb/Desktop/projects/digital_simulation_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libinclude.a"
	cd /home/seb/Desktop/projects/digital_simulation_project/build/src && $(CMAKE_COMMAND) -P CMakeFiles/include.dir/cmake_clean_target.cmake
	cd /home/seb/Desktop/projects/digital_simulation_project/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/include.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/include.dir/build: src/libinclude.a
.PHONY : src/CMakeFiles/include.dir/build

src/CMakeFiles/include.dir/clean:
	cd /home/seb/Desktop/projects/digital_simulation_project/build/src && $(CMAKE_COMMAND) -P CMakeFiles/include.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/include.dir/clean

src/CMakeFiles/include.dir/depend:
	cd /home/seb/Desktop/projects/digital_simulation_project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/seb/Desktop/projects/digital_simulation_project /home/seb/Desktop/projects/digital_simulation_project/src /home/seb/Desktop/projects/digital_simulation_project/build /home/seb/Desktop/projects/digital_simulation_project/build/src /home/seb/Desktop/projects/digital_simulation_project/build/src/CMakeFiles/include.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/include.dir/depend

