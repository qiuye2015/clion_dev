# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\jianpeng10\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.3345.126\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\jianpeng10\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.3345.126\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\code\clion_dev

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\code\clion_dev\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/clion_dev.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/clion_dev.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/clion_dev.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/clion_dev.dir/flags.make

CMakeFiles/clion_dev.dir/main.cpp.obj: CMakeFiles/clion_dev.dir/flags.make
CMakeFiles/clion_dev.dir/main.cpp.obj: CMakeFiles/clion_dev.dir/includes_CXX.rsp
CMakeFiles/clion_dev.dir/main.cpp.obj: ../main.cpp
CMakeFiles/clion_dev.dir/main.cpp.obj: CMakeFiles/clion_dev.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\code\clion_dev\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/clion_dev.dir/main.cpp.obj"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/clion_dev.dir/main.cpp.obj -MF CMakeFiles\clion_dev.dir\main.cpp.obj.d -o CMakeFiles\clion_dev.dir\main.cpp.obj -c D:\code\clion_dev\main.cpp

CMakeFiles/clion_dev.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/clion_dev.dir/main.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\code\clion_dev\main.cpp > CMakeFiles\clion_dev.dir\main.cpp.i

CMakeFiles/clion_dev.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/clion_dev.dir/main.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\code\clion_dev\main.cpp -o CMakeFiles\clion_dev.dir\main.cpp.s

# Object files for target clion_dev
clion_dev_OBJECTS = \
"CMakeFiles/clion_dev.dir/main.cpp.obj"

# External object files for target clion_dev
clion_dev_EXTERNAL_OBJECTS =

clion_dev.exe: CMakeFiles/clion_dev.dir/main.cpp.obj
clion_dev.exe: CMakeFiles/clion_dev.dir/build.make
clion_dev.exe: CMakeFiles/clion_dev.dir/linklibs.rsp
clion_dev.exe: CMakeFiles/clion_dev.dir/objects1.rsp
clion_dev.exe: CMakeFiles/clion_dev.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\code\clion_dev\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable clion_dev.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\clion_dev.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/clion_dev.dir/build: clion_dev.exe
.PHONY : CMakeFiles/clion_dev.dir/build

CMakeFiles/clion_dev.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\clion_dev.dir\cmake_clean.cmake
.PHONY : CMakeFiles/clion_dev.dir/clean

CMakeFiles/clion_dev.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\code\clion_dev D:\code\clion_dev D:\code\clion_dev\cmake-build-debug D:\code\clion_dev\cmake-build-debug D:\code\clion_dev\cmake-build-debug\CMakeFiles\clion_dev.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/clion_dev.dir/depend
