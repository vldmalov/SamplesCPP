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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/vladimirmalov/Documents/Vldmalov/SamplesCPP/SapLessons/2021/StringClass

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/vladimirmalov/Documents/Vldmalov/SamplesCPP/SapLessons/2021/StringClass/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/StringClass.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/StringClass.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/StringClass.dir/flags.make

CMakeFiles/StringClass.dir/main.cpp.o: CMakeFiles/StringClass.dir/flags.make
CMakeFiles/StringClass.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vladimirmalov/Documents/Vldmalov/SamplesCPP/SapLessons/2021/StringClass/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/StringClass.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/StringClass.dir/main.cpp.o -c /Users/vladimirmalov/Documents/Vldmalov/SamplesCPP/SapLessons/2021/StringClass/main.cpp

CMakeFiles/StringClass.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StringClass.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vladimirmalov/Documents/Vldmalov/SamplesCPP/SapLessons/2021/StringClass/main.cpp > CMakeFiles/StringClass.dir/main.cpp.i

CMakeFiles/StringClass.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StringClass.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vladimirmalov/Documents/Vldmalov/SamplesCPP/SapLessons/2021/StringClass/main.cpp -o CMakeFiles/StringClass.dir/main.cpp.s

CMakeFiles/StringClass.dir/MyString.cpp.o: CMakeFiles/StringClass.dir/flags.make
CMakeFiles/StringClass.dir/MyString.cpp.o: ../MyString.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vladimirmalov/Documents/Vldmalov/SamplesCPP/SapLessons/2021/StringClass/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/StringClass.dir/MyString.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/StringClass.dir/MyString.cpp.o -c /Users/vladimirmalov/Documents/Vldmalov/SamplesCPP/SapLessons/2021/StringClass/MyString.cpp

CMakeFiles/StringClass.dir/MyString.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StringClass.dir/MyString.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vladimirmalov/Documents/Vldmalov/SamplesCPP/SapLessons/2021/StringClass/MyString.cpp > CMakeFiles/StringClass.dir/MyString.cpp.i

CMakeFiles/StringClass.dir/MyString.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StringClass.dir/MyString.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vladimirmalov/Documents/Vldmalov/SamplesCPP/SapLessons/2021/StringClass/MyString.cpp -o CMakeFiles/StringClass.dir/MyString.cpp.s

# Object files for target StringClass
StringClass_OBJECTS = \
"CMakeFiles/StringClass.dir/main.cpp.o" \
"CMakeFiles/StringClass.dir/MyString.cpp.o"

# External object files for target StringClass
StringClass_EXTERNAL_OBJECTS =

StringClass: CMakeFiles/StringClass.dir/main.cpp.o
StringClass: CMakeFiles/StringClass.dir/MyString.cpp.o
StringClass: CMakeFiles/StringClass.dir/build.make
StringClass: CMakeFiles/StringClass.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/vladimirmalov/Documents/Vldmalov/SamplesCPP/SapLessons/2021/StringClass/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable StringClass"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/StringClass.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/StringClass.dir/build: StringClass
.PHONY : CMakeFiles/StringClass.dir/build

CMakeFiles/StringClass.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/StringClass.dir/cmake_clean.cmake
.PHONY : CMakeFiles/StringClass.dir/clean

CMakeFiles/StringClass.dir/depend:
	cd /Users/vladimirmalov/Documents/Vldmalov/SamplesCPP/SapLessons/2021/StringClass/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/vladimirmalov/Documents/Vldmalov/SamplesCPP/SapLessons/2021/StringClass /Users/vladimirmalov/Documents/Vldmalov/SamplesCPP/SapLessons/2021/StringClass /Users/vladimirmalov/Documents/Vldmalov/SamplesCPP/SapLessons/2021/StringClass/cmake-build-debug /Users/vladimirmalov/Documents/Vldmalov/SamplesCPP/SapLessons/2021/StringClass/cmake-build-debug /Users/vladimirmalov/Documents/Vldmalov/SamplesCPP/SapLessons/2021/StringClass/cmake-build-debug/CMakeFiles/StringClass.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/StringClass.dir/depend
