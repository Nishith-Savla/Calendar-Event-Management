# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\CLion\Calendar-Event-Management

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\CLion\Calendar-Event-Management\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CalendarEventManagement.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CalendarEventManagement.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CalendarEventManagement.dir/flags.make

CMakeFiles/CalendarEventManagement.dir/main.cpp.obj: CMakeFiles/CalendarEventManagement.dir/flags.make
CMakeFiles/CalendarEventManagement.dir/main.cpp.obj: CMakeFiles/CalendarEventManagement.dir/includes_CXX.rsp
CMakeFiles/CalendarEventManagement.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\CLion\Calendar-Event-Management\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CalendarEventManagement.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CalendarEventManagement.dir\main.cpp.obj -c D:\CLion\Calendar-Event-Management\main.cpp

CMakeFiles/CalendarEventManagement.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CalendarEventManagement.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\CLion\Calendar-Event-Management\main.cpp > CMakeFiles\CalendarEventManagement.dir\main.cpp.i

CMakeFiles/CalendarEventManagement.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CalendarEventManagement.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\CLion\Calendar-Event-Management\main.cpp -o CMakeFiles\CalendarEventManagement.dir\main.cpp.s

CMakeFiles/CalendarEventManagement.dir/Event.cpp.obj: CMakeFiles/CalendarEventManagement.dir/flags.make
CMakeFiles/CalendarEventManagement.dir/Event.cpp.obj: CMakeFiles/CalendarEventManagement.dir/includes_CXX.rsp
CMakeFiles/CalendarEventManagement.dir/Event.cpp.obj: ../Event.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\CLion\Calendar-Event-Management\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CalendarEventManagement.dir/Event.cpp.obj"
	C:\PROGRA~1\MINGW-~1\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CalendarEventManagement.dir\Event.cpp.obj -c D:\CLion\Calendar-Event-Management\Event.cpp

CMakeFiles/CalendarEventManagement.dir/Event.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CalendarEventManagement.dir/Event.cpp.i"
	C:\PROGRA~1\MINGW-~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\CLion\Calendar-Event-Management\Event.cpp > CMakeFiles\CalendarEventManagement.dir\Event.cpp.i

CMakeFiles/CalendarEventManagement.dir/Event.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CalendarEventManagement.dir/Event.cpp.s"
	C:\PROGRA~1\MINGW-~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\CLion\Calendar-Event-Management\Event.cpp -o CMakeFiles\CalendarEventManagement.dir\Event.cpp.s

# Object files for target CalendarEventManagement
CalendarEventManagement_OBJECTS = \
"CMakeFiles/CalendarEventManagement.dir/main.cpp.obj" \
"CMakeFiles/CalendarEventManagement.dir/Event.cpp.obj"

# External object files for target CalendarEventManagement
CalendarEventManagement_EXTERNAL_OBJECTS =

CalendarEventManagement.exe: CMakeFiles/CalendarEventManagement.dir/main.cpp.obj
CalendarEventManagement.exe: CMakeFiles/CalendarEventManagement.dir/Event.cpp.obj
CalendarEventManagement.exe: CMakeFiles/CalendarEventManagement.dir/build.make
CalendarEventManagement.exe: C:/sqlite/sqlite3.dll
CalendarEventManagement.exe: CMakeFiles/CalendarEventManagement.dir/linklibs.rsp
CalendarEventManagement.exe: CMakeFiles/CalendarEventManagement.dir/objects1.rsp
CalendarEventManagement.exe: CMakeFiles/CalendarEventManagement.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\CLion\Calendar-Event-Management\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable CalendarEventManagement.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\CalendarEventManagement.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CalendarEventManagement.dir/build: CalendarEventManagement.exe

.PHONY : CMakeFiles/CalendarEventManagement.dir/build

CMakeFiles/CalendarEventManagement.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\CalendarEventManagement.dir\cmake_clean.cmake
.PHONY : CMakeFiles/CalendarEventManagement.dir/clean

CMakeFiles/CalendarEventManagement.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\CLion\Calendar-Event-Management D:\CLion\Calendar-Event-Management D:\CLion\Calendar-Event-Management\cmake-build-debug D:\CLion\Calendar-Event-Management\cmake-build-debug D:\CLion\Calendar-Event-Management\cmake-build-debug\CMakeFiles\CalendarEventManagement.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CalendarEventManagement.dir/depend

