# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = C:\msys64\mingw64\bin\cmake.exe

# The command to remove a file.
RM = C:\msys64\mingw64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Development\Tactics

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Development\Tactics\build

# Include any dependencies generated for this target.
include CMakeFiles/Tactics-Server.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Tactics-Server.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Tactics-Server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Tactics-Server.dir/flags.make

CMakeFiles/Tactics-Server.dir/src/server/main.cpp.obj: CMakeFiles/Tactics-Server.dir/flags.make
CMakeFiles/Tactics-Server.dir/src/server/main.cpp.obj: CMakeFiles/Tactics-Server.dir/includes_CXX.rsp
CMakeFiles/Tactics-Server.dir/src/server/main.cpp.obj: D:/Development/Tactics/src/server/main.cpp
CMakeFiles/Tactics-Server.dir/src/server/main.cpp.obj: CMakeFiles/Tactics-Server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\Development\Tactics\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Tactics-Server.dir/src/server/main.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Tactics-Server.dir/src/server/main.cpp.obj -MF CMakeFiles\Tactics-Server.dir\src\server\main.cpp.obj.d -o CMakeFiles\Tactics-Server.dir\src\server\main.cpp.obj -c D:\Development\Tactics\src\server\main.cpp

CMakeFiles/Tactics-Server.dir/src/server/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Tactics-Server.dir/src/server/main.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Development\Tactics\src\server\main.cpp > CMakeFiles\Tactics-Server.dir\src\server\main.cpp.i

CMakeFiles/Tactics-Server.dir/src/server/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Tactics-Server.dir/src/server/main.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Development\Tactics\src\server\main.cpp -o CMakeFiles\Tactics-Server.dir\src\server\main.cpp.s

CMakeFiles/Tactics-Server.dir/src/server/connection/Server.cpp.obj: CMakeFiles/Tactics-Server.dir/flags.make
CMakeFiles/Tactics-Server.dir/src/server/connection/Server.cpp.obj: CMakeFiles/Tactics-Server.dir/includes_CXX.rsp
CMakeFiles/Tactics-Server.dir/src/server/connection/Server.cpp.obj: D:/Development/Tactics/src/server/connection/Server.cpp
CMakeFiles/Tactics-Server.dir/src/server/connection/Server.cpp.obj: CMakeFiles/Tactics-Server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\Development\Tactics\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Tactics-Server.dir/src/server/connection/Server.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Tactics-Server.dir/src/server/connection/Server.cpp.obj -MF CMakeFiles\Tactics-Server.dir\src\server\connection\Server.cpp.obj.d -o CMakeFiles\Tactics-Server.dir\src\server\connection\Server.cpp.obj -c D:\Development\Tactics\src\server\connection\Server.cpp

CMakeFiles/Tactics-Server.dir/src/server/connection/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Tactics-Server.dir/src/server/connection/Server.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Development\Tactics\src\server\connection\Server.cpp > CMakeFiles\Tactics-Server.dir\src\server\connection\Server.cpp.i

CMakeFiles/Tactics-Server.dir/src/server/connection/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Tactics-Server.dir/src/server/connection/Server.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Development\Tactics\src\server\connection\Server.cpp -o CMakeFiles\Tactics-Server.dir\src\server\connection\Server.cpp.s

CMakeFiles/Tactics-Server.dir/src/server/connection/PacketHandler.cpp.obj: CMakeFiles/Tactics-Server.dir/flags.make
CMakeFiles/Tactics-Server.dir/src/server/connection/PacketHandler.cpp.obj: CMakeFiles/Tactics-Server.dir/includes_CXX.rsp
CMakeFiles/Tactics-Server.dir/src/server/connection/PacketHandler.cpp.obj: D:/Development/Tactics/src/server/connection/PacketHandler.cpp
CMakeFiles/Tactics-Server.dir/src/server/connection/PacketHandler.cpp.obj: CMakeFiles/Tactics-Server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\Development\Tactics\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Tactics-Server.dir/src/server/connection/PacketHandler.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Tactics-Server.dir/src/server/connection/PacketHandler.cpp.obj -MF CMakeFiles\Tactics-Server.dir\src\server\connection\PacketHandler.cpp.obj.d -o CMakeFiles\Tactics-Server.dir\src\server\connection\PacketHandler.cpp.obj -c D:\Development\Tactics\src\server\connection\PacketHandler.cpp

CMakeFiles/Tactics-Server.dir/src/server/connection/PacketHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Tactics-Server.dir/src/server/connection/PacketHandler.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Development\Tactics\src\server\connection\PacketHandler.cpp > CMakeFiles\Tactics-Server.dir\src\server\connection\PacketHandler.cpp.i

CMakeFiles/Tactics-Server.dir/src/server/connection/PacketHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Tactics-Server.dir/src/server/connection/PacketHandler.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Development\Tactics\src\server\connection\PacketHandler.cpp -o CMakeFiles\Tactics-Server.dir\src\server\connection\PacketHandler.cpp.s

CMakeFiles/Tactics-Server.dir/src/server/gui/ConsoleWindow.cpp.obj: CMakeFiles/Tactics-Server.dir/flags.make
CMakeFiles/Tactics-Server.dir/src/server/gui/ConsoleWindow.cpp.obj: CMakeFiles/Tactics-Server.dir/includes_CXX.rsp
CMakeFiles/Tactics-Server.dir/src/server/gui/ConsoleWindow.cpp.obj: D:/Development/Tactics/src/server/gui/ConsoleWindow.cpp
CMakeFiles/Tactics-Server.dir/src/server/gui/ConsoleWindow.cpp.obj: CMakeFiles/Tactics-Server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\Development\Tactics\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Tactics-Server.dir/src/server/gui/ConsoleWindow.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Tactics-Server.dir/src/server/gui/ConsoleWindow.cpp.obj -MF CMakeFiles\Tactics-Server.dir\src\server\gui\ConsoleWindow.cpp.obj.d -o CMakeFiles\Tactics-Server.dir\src\server\gui\ConsoleWindow.cpp.obj -c D:\Development\Tactics\src\server\gui\ConsoleWindow.cpp

CMakeFiles/Tactics-Server.dir/src/server/gui/ConsoleWindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Tactics-Server.dir/src/server/gui/ConsoleWindow.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Development\Tactics\src\server\gui\ConsoleWindow.cpp > CMakeFiles\Tactics-Server.dir\src\server\gui\ConsoleWindow.cpp.i

CMakeFiles/Tactics-Server.dir/src/server/gui/ConsoleWindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Tactics-Server.dir/src/server/gui/ConsoleWindow.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Development\Tactics\src\server\gui\ConsoleWindow.cpp -o CMakeFiles\Tactics-Server.dir\src\server\gui\ConsoleWindow.cpp.s

# Object files for target Tactics-Server
Tactics__Server_OBJECTS = \
"CMakeFiles/Tactics-Server.dir/src/server/main.cpp.obj" \
"CMakeFiles/Tactics-Server.dir/src/server/connection/Server.cpp.obj" \
"CMakeFiles/Tactics-Server.dir/src/server/connection/PacketHandler.cpp.obj" \
"CMakeFiles/Tactics-Server.dir/src/server/gui/ConsoleWindow.cpp.obj"

# External object files for target Tactics-Server
Tactics__Server_EXTERNAL_OBJECTS =

Tactics-Server.exe: CMakeFiles/Tactics-Server.dir/src/server/main.cpp.obj
Tactics-Server.exe: CMakeFiles/Tactics-Server.dir/src/server/connection/Server.cpp.obj
Tactics-Server.exe: CMakeFiles/Tactics-Server.dir/src/server/connection/PacketHandler.cpp.obj
Tactics-Server.exe: CMakeFiles/Tactics-Server.dir/src/server/gui/ConsoleWindow.cpp.obj
Tactics-Server.exe: CMakeFiles/Tactics-Server.dir/build.make
Tactics-Server.exe: D:/Development/Tactics/lib/SFML-3.0.0/lib/libsfml-graphics-s.a
Tactics-Server.exe: D:/Development/Tactics/lib/SFML-3.0.0/lib/libsfml-window-s.a
Tactics-Server.exe: D:/Development/Tactics/lib/SFML-3.0.0/lib/libsfml-system-s.a
Tactics-Server.exe: D:/Development/Tactics/lib/freetype/lib/freetype.a
Tactics-Server.exe: D:/Development/Tactics/lib/enet/lib/libenet.a
Tactics-Server.exe: CMakeFiles/Tactics-Server.dir/linkLibs.rsp
Tactics-Server.exe: CMakeFiles/Tactics-Server.dir/objects1.rsp
Tactics-Server.exe: CMakeFiles/Tactics-Server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=D:\Development\Tactics\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable Tactics-Server.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Tactics-Server.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Tactics-Server.dir/build: Tactics-Server.exe
.PHONY : CMakeFiles/Tactics-Server.dir/build

CMakeFiles/Tactics-Server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Tactics-Server.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Tactics-Server.dir/clean

CMakeFiles/Tactics-Server.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Development\Tactics D:\Development\Tactics D:\Development\Tactics\build D:\Development\Tactics\build D:\Development\Tactics\build\CMakeFiles\Tactics-Server.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Tactics-Server.dir/depend

