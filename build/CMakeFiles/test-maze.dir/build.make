# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = "C:/Program Files/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files/CMake/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:/Users/danim/OneDrive/Documents/GitHub/micromouse2023

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:/Users/danim/OneDrive/Documents/GitHub/micromouse2023/build

# Include any dependencies generated for this target.
include CMakeFiles/test-maze.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test-maze.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test-maze.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test-maze.dir/flags.make

CMakeFiles/test-maze.dir/maze.cpp.obj: CMakeFiles/test-maze.dir/flags.make
CMakeFiles/test-maze.dir/maze.cpp.obj: C:/Users/danim/OneDrive/Documents/GitHub/micromouse2023/maze.cpp
CMakeFiles/test-maze.dir/maze.cpp.obj: CMakeFiles/test-maze.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:/Users/danim/OneDrive/Documents/GitHub/micromouse2023/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test-maze.dir/maze.cpp.obj"
	C:/msys64/ucrt64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test-maze.dir/maze.cpp.obj -MF CMakeFiles/test-maze.dir/maze.cpp.obj.d -o CMakeFiles/test-maze.dir/maze.cpp.obj -c C:/Users/danim/OneDrive/Documents/GitHub/micromouse2023/maze.cpp

CMakeFiles/test-maze.dir/maze.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test-maze.dir/maze.cpp.i"
	C:/msys64/ucrt64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:/Users/danim/OneDrive/Documents/GitHub/micromouse2023/maze.cpp > CMakeFiles/test-maze.dir/maze.cpp.i

CMakeFiles/test-maze.dir/maze.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test-maze.dir/maze.cpp.s"
	C:/msys64/ucrt64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:/Users/danim/OneDrive/Documents/GitHub/micromouse2023/maze.cpp -o CMakeFiles/test-maze.dir/maze.cpp.s

CMakeFiles/test-maze.dir/mouse.cpp.obj: CMakeFiles/test-maze.dir/flags.make
CMakeFiles/test-maze.dir/mouse.cpp.obj: C:/Users/danim/OneDrive/Documents/GitHub/micromouse2023/mouse.cpp
CMakeFiles/test-maze.dir/mouse.cpp.obj: CMakeFiles/test-maze.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:/Users/danim/OneDrive/Documents/GitHub/micromouse2023/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/test-maze.dir/mouse.cpp.obj"
	C:/msys64/ucrt64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test-maze.dir/mouse.cpp.obj -MF CMakeFiles/test-maze.dir/mouse.cpp.obj.d -o CMakeFiles/test-maze.dir/mouse.cpp.obj -c C:/Users/danim/OneDrive/Documents/GitHub/micromouse2023/mouse.cpp

CMakeFiles/test-maze.dir/mouse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test-maze.dir/mouse.cpp.i"
	C:/msys64/ucrt64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:/Users/danim/OneDrive/Documents/GitHub/micromouse2023/mouse.cpp > CMakeFiles/test-maze.dir/mouse.cpp.i

CMakeFiles/test-maze.dir/mouse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test-maze.dir/mouse.cpp.s"
	C:/msys64/ucrt64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:/Users/danim/OneDrive/Documents/GitHub/micromouse2023/mouse.cpp -o CMakeFiles/test-maze.dir/mouse.cpp.s

CMakeFiles/test-maze.dir/test_maze.cpp.obj: CMakeFiles/test-maze.dir/flags.make
CMakeFiles/test-maze.dir/test_maze.cpp.obj: C:/Users/danim/OneDrive/Documents/GitHub/micromouse2023/test_maze.cpp
CMakeFiles/test-maze.dir/test_maze.cpp.obj: CMakeFiles/test-maze.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:/Users/danim/OneDrive/Documents/GitHub/micromouse2023/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/test-maze.dir/test_maze.cpp.obj"
	C:/msys64/ucrt64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test-maze.dir/test_maze.cpp.obj -MF CMakeFiles/test-maze.dir/test_maze.cpp.obj.d -o CMakeFiles/test-maze.dir/test_maze.cpp.obj -c C:/Users/danim/OneDrive/Documents/GitHub/micromouse2023/test_maze.cpp

CMakeFiles/test-maze.dir/test_maze.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test-maze.dir/test_maze.cpp.i"
	C:/msys64/ucrt64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:/Users/danim/OneDrive/Documents/GitHub/micromouse2023/test_maze.cpp > CMakeFiles/test-maze.dir/test_maze.cpp.i

CMakeFiles/test-maze.dir/test_maze.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test-maze.dir/test_maze.cpp.s"
	C:/msys64/ucrt64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:/Users/danim/OneDrive/Documents/GitHub/micromouse2023/test_maze.cpp -o CMakeFiles/test-maze.dir/test_maze.cpp.s

# Object files for target test-maze
test__maze_OBJECTS = \
"CMakeFiles/test-maze.dir/maze.cpp.obj" \
"CMakeFiles/test-maze.dir/mouse.cpp.obj" \
"CMakeFiles/test-maze.dir/test_maze.cpp.obj"

# External object files for target test-maze
test__maze_EXTERNAL_OBJECTS =

test-maze.exe: CMakeFiles/test-maze.dir/maze.cpp.obj
test-maze.exe: CMakeFiles/test-maze.dir/mouse.cpp.obj
test-maze.exe: CMakeFiles/test-maze.dir/test_maze.cpp.obj
test-maze.exe: CMakeFiles/test-maze.dir/build.make
test-maze.exe: CMakeFiles/test-maze.dir/linkLibs.rsp
test-maze.exe: CMakeFiles/test-maze.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:/Users/danim/OneDrive/Documents/GitHub/micromouse2023/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable test-maze.exe"
	"C:/Program Files/CMake/bin/cmake.exe" -E rm -f CMakeFiles/test-maze.dir/objects.a
	C:/msys64/ucrt64/bin/ar.exe qc CMakeFiles/test-maze.dir/objects.a @CMakeFiles/test-maze.dir/objects1.rsp
	C:/msys64/ucrt64/bin/g++.exe -g -Wl,--whole-archive CMakeFiles/test-maze.dir/objects.a -Wl,--no-whole-archive -o test-maze.exe -Wl,--out-implib,libtest-maze.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/test-maze.dir/linkLibs.rsp

# Rule to build all files generated by this target.
CMakeFiles/test-maze.dir/build: test-maze.exe
.PHONY : CMakeFiles/test-maze.dir/build

CMakeFiles/test-maze.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test-maze.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test-maze.dir/clean

CMakeFiles/test-maze.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" C:/Users/danim/OneDrive/Documents/GitHub/micromouse2023 C:/Users/danim/OneDrive/Documents/GitHub/micromouse2023 C:/Users/danim/OneDrive/Documents/GitHub/micromouse2023/build C:/Users/danim/OneDrive/Documents/GitHub/micromouse2023/build C:/Users/danim/OneDrive/Documents/GitHub/micromouse2023/build/CMakeFiles/test-maze.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/test-maze.dir/depend

