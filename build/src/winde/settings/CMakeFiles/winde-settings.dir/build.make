# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_SOURCE_DIR = /home/jjshandy6161/Public/WinDE

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jjshandy6161/Public/WinDE/build

# Include any dependencies generated for this target.
include src/winde/settings/CMakeFiles/winde-settings.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/winde/settings/CMakeFiles/winde-settings.dir/compiler_depend.make

# Include the progress variables for this target.
include src/winde/settings/CMakeFiles/winde-settings.dir/progress.make

# Include the compile flags for this target's objects.
include src/winde/settings/CMakeFiles/winde-settings.dir/flags.make

src/winde/settings/CMakeFiles/winde-settings.dir/codegen:
.PHONY : src/winde/settings/CMakeFiles/winde-settings.dir/codegen

src/winde/settings/CMakeFiles/winde-settings.dir/winde-settings_autogen/mocs_compilation.cpp.o: src/winde/settings/CMakeFiles/winde-settings.dir/flags.make
src/winde/settings/CMakeFiles/winde-settings.dir/winde-settings_autogen/mocs_compilation.cpp.o: src/winde/settings/winde-settings_autogen/mocs_compilation.cpp
src/winde/settings/CMakeFiles/winde-settings.dir/winde-settings_autogen/mocs_compilation.cpp.o: src/winde/settings/CMakeFiles/winde-settings.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/jjshandy6161/Public/WinDE/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/winde/settings/CMakeFiles/winde-settings.dir/winde-settings_autogen/mocs_compilation.cpp.o"
	cd /home/jjshandy6161/Public/WinDE/build/src/winde/settings && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/winde/settings/CMakeFiles/winde-settings.dir/winde-settings_autogen/mocs_compilation.cpp.o -MF CMakeFiles/winde-settings.dir/winde-settings_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/winde-settings.dir/winde-settings_autogen/mocs_compilation.cpp.o -c /home/jjshandy6161/Public/WinDE/build/src/winde/settings/winde-settings_autogen/mocs_compilation.cpp

src/winde/settings/CMakeFiles/winde-settings.dir/winde-settings_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/winde-settings.dir/winde-settings_autogen/mocs_compilation.cpp.i"
	cd /home/jjshandy6161/Public/WinDE/build/src/winde/settings && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jjshandy6161/Public/WinDE/build/src/winde/settings/winde-settings_autogen/mocs_compilation.cpp > CMakeFiles/winde-settings.dir/winde-settings_autogen/mocs_compilation.cpp.i

src/winde/settings/CMakeFiles/winde-settings.dir/winde-settings_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/winde-settings.dir/winde-settings_autogen/mocs_compilation.cpp.s"
	cd /home/jjshandy6161/Public/WinDE/build/src/winde/settings && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jjshandy6161/Public/WinDE/build/src/winde/settings/winde-settings_autogen/mocs_compilation.cpp -o CMakeFiles/winde-settings.dir/winde-settings_autogen/mocs_compilation.cpp.s

# Object files for target winde-settings
winde__settings_OBJECTS = \
"CMakeFiles/winde-settings.dir/winde-settings_autogen/mocs_compilation.cpp.o"

# External object files for target winde-settings
winde__settings_EXTERNAL_OBJECTS =

lib/libwinde-settings.a: src/winde/settings/CMakeFiles/winde-settings.dir/winde-settings_autogen/mocs_compilation.cpp.o
lib/libwinde-settings.a: src/winde/settings/CMakeFiles/winde-settings.dir/build.make
lib/libwinde-settings.a: src/winde/settings/CMakeFiles/winde-settings.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/jjshandy6161/Public/WinDE/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../../lib/libwinde-settings.a"
	cd /home/jjshandy6161/Public/WinDE/build/src/winde/settings && $(CMAKE_COMMAND) -P CMakeFiles/winde-settings.dir/cmake_clean_target.cmake
	cd /home/jjshandy6161/Public/WinDE/build/src/winde/settings && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/winde-settings.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/winde/settings/CMakeFiles/winde-settings.dir/build: lib/libwinde-settings.a
.PHONY : src/winde/settings/CMakeFiles/winde-settings.dir/build

src/winde/settings/CMakeFiles/winde-settings.dir/clean:
	cd /home/jjshandy6161/Public/WinDE/build/src/winde/settings && $(CMAKE_COMMAND) -P CMakeFiles/winde-settings.dir/cmake_clean.cmake
.PHONY : src/winde/settings/CMakeFiles/winde-settings.dir/clean

src/winde/settings/CMakeFiles/winde-settings.dir/depend:
	cd /home/jjshandy6161/Public/WinDE/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jjshandy6161/Public/WinDE /home/jjshandy6161/Public/WinDE/src/winde/settings /home/jjshandy6161/Public/WinDE/build /home/jjshandy6161/Public/WinDE/build/src/winde/settings /home/jjshandy6161/Public/WinDE/build/src/winde/settings/CMakeFiles/winde-settings.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/winde/settings/CMakeFiles/winde-settings.dir/depend

