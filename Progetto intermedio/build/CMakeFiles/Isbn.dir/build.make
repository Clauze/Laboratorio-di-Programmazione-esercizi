# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\claud\Desktop\Lab di programmazione\Laboratorio-di-programmazione"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\claud\Desktop\Lab di programmazione\Laboratorio-di-programmazione\build"

# Include any dependencies generated for this target.
include CMakeFiles/Isbn.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Isbn.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Isbn.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Isbn.dir/flags.make

CMakeFiles/Isbn.dir/src/Isbn.cpp.obj: CMakeFiles/Isbn.dir/flags.make
CMakeFiles/Isbn.dir/src/Isbn.cpp.obj: CMakeFiles/Isbn.dir/includes_CXX.rsp
CMakeFiles/Isbn.dir/src/Isbn.cpp.obj: C:/Users/claud/Desktop/Lab\ di\ programmazione/Laboratorio-di-programmazione/src/Isbn.cpp
CMakeFiles/Isbn.dir/src/Isbn.cpp.obj: CMakeFiles/Isbn.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\claud\Desktop\Lab di programmazione\Laboratorio-di-programmazione\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Isbn.dir/src/Isbn.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Isbn.dir/src/Isbn.cpp.obj -MF CMakeFiles\Isbn.dir\src\Isbn.cpp.obj.d -o CMakeFiles\Isbn.dir\src\Isbn.cpp.obj -c "C:\Users\claud\Desktop\Lab di programmazione\Laboratorio-di-programmazione\src\Isbn.cpp"

CMakeFiles/Isbn.dir/src/Isbn.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Isbn.dir/src/Isbn.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\claud\Desktop\Lab di programmazione\Laboratorio-di-programmazione\src\Isbn.cpp" > CMakeFiles\Isbn.dir\src\Isbn.cpp.i

CMakeFiles/Isbn.dir/src/Isbn.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Isbn.dir/src/Isbn.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\claud\Desktop\Lab di programmazione\Laboratorio-di-programmazione\src\Isbn.cpp" -o CMakeFiles\Isbn.dir\src\Isbn.cpp.s

# Object files for target Isbn
Isbn_OBJECTS = \
"CMakeFiles/Isbn.dir/src/Isbn.cpp.obj"

# External object files for target Isbn
Isbn_EXTERNAL_OBJECTS =

libIsbn.a: CMakeFiles/Isbn.dir/src/Isbn.cpp.obj
libIsbn.a: CMakeFiles/Isbn.dir/build.make
libIsbn.a: CMakeFiles/Isbn.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\claud\Desktop\Lab di programmazione\Laboratorio-di-programmazione\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libIsbn.a"
	$(CMAKE_COMMAND) -P CMakeFiles\Isbn.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Isbn.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Isbn.dir/build: libIsbn.a
.PHONY : CMakeFiles/Isbn.dir/build

CMakeFiles/Isbn.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Isbn.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Isbn.dir/clean

CMakeFiles/Isbn.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\claud\Desktop\Lab di programmazione\Laboratorio-di-programmazione" "C:\Users\claud\Desktop\Lab di programmazione\Laboratorio-di-programmazione" "C:\Users\claud\Desktop\Lab di programmazione\Laboratorio-di-programmazione\build" "C:\Users\claud\Desktop\Lab di programmazione\Laboratorio-di-programmazione\build" "C:\Users\claud\Desktop\Lab di programmazione\Laboratorio-di-programmazione\build\CMakeFiles\Isbn.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Isbn.dir/depend
