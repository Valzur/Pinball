# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /snap/clion/107/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/107/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/anon/Desktop/Pinball Khaled Recom/Pinball"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/anon/Desktop/Pinball Khaled Recom/Pinball/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Pinball.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Pinball.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Pinball.dir/flags.make

CMakeFiles/Pinball.dir/main.cpp.o: CMakeFiles/Pinball.dir/flags.make
CMakeFiles/Pinball.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/anon/Desktop/Pinball Khaled Recom/Pinball/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Pinball.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Pinball.dir/main.cpp.o -c "/home/anon/Desktop/Pinball Khaled Recom/Pinball/main.cpp"

CMakeFiles/Pinball.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pinball.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/anon/Desktop/Pinball Khaled Recom/Pinball/main.cpp" > CMakeFiles/Pinball.dir/main.cpp.i

CMakeFiles/Pinball.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pinball.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/anon/Desktop/Pinball Khaled Recom/Pinball/main.cpp" -o CMakeFiles/Pinball.dir/main.cpp.s

CMakeFiles/Pinball.dir/Game.cpp.o: CMakeFiles/Pinball.dir/flags.make
CMakeFiles/Pinball.dir/Game.cpp.o: ../Game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/anon/Desktop/Pinball Khaled Recom/Pinball/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Pinball.dir/Game.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Pinball.dir/Game.cpp.o -c "/home/anon/Desktop/Pinball Khaled Recom/Pinball/Game.cpp"

CMakeFiles/Pinball.dir/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pinball.dir/Game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/anon/Desktop/Pinball Khaled Recom/Pinball/Game.cpp" > CMakeFiles/Pinball.dir/Game.cpp.i

CMakeFiles/Pinball.dir/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pinball.dir/Game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/anon/Desktop/Pinball Khaled Recom/Pinball/Game.cpp" -o CMakeFiles/Pinball.dir/Game.cpp.s

CMakeFiles/Pinball.dir/Interface.cpp.o: CMakeFiles/Pinball.dir/flags.make
CMakeFiles/Pinball.dir/Interface.cpp.o: ../Interface.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/anon/Desktop/Pinball Khaled Recom/Pinball/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Pinball.dir/Interface.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Pinball.dir/Interface.cpp.o -c "/home/anon/Desktop/Pinball Khaled Recom/Pinball/Interface.cpp"

CMakeFiles/Pinball.dir/Interface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pinball.dir/Interface.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/anon/Desktop/Pinball Khaled Recom/Pinball/Interface.cpp" > CMakeFiles/Pinball.dir/Interface.cpp.i

CMakeFiles/Pinball.dir/Interface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pinball.dir/Interface.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/anon/Desktop/Pinball Khaled Recom/Pinball/Interface.cpp" -o CMakeFiles/Pinball.dir/Interface.cpp.s

CMakeFiles/Pinball.dir/GameObjects/Ball.cpp.o: CMakeFiles/Pinball.dir/flags.make
CMakeFiles/Pinball.dir/GameObjects/Ball.cpp.o: ../GameObjects/Ball.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/anon/Desktop/Pinball Khaled Recom/Pinball/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Pinball.dir/GameObjects/Ball.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Pinball.dir/GameObjects/Ball.cpp.o -c "/home/anon/Desktop/Pinball Khaled Recom/Pinball/GameObjects/Ball.cpp"

CMakeFiles/Pinball.dir/GameObjects/Ball.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pinball.dir/GameObjects/Ball.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/anon/Desktop/Pinball Khaled Recom/Pinball/GameObjects/Ball.cpp" > CMakeFiles/Pinball.dir/GameObjects/Ball.cpp.i

CMakeFiles/Pinball.dir/GameObjects/Ball.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pinball.dir/GameObjects/Ball.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/anon/Desktop/Pinball Khaled Recom/Pinball/GameObjects/Ball.cpp" -o CMakeFiles/Pinball.dir/GameObjects/Ball.cpp.s

CMakeFiles/Pinball.dir/GameObjects/Obstacles/Wall.cpp.o: CMakeFiles/Pinball.dir/flags.make
CMakeFiles/Pinball.dir/GameObjects/Obstacles/Wall.cpp.o: ../GameObjects/Obstacles/Wall.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/anon/Desktop/Pinball Khaled Recom/Pinball/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Pinball.dir/GameObjects/Obstacles/Wall.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Pinball.dir/GameObjects/Obstacles/Wall.cpp.o -c "/home/anon/Desktop/Pinball Khaled Recom/Pinball/GameObjects/Obstacles/Wall.cpp"

CMakeFiles/Pinball.dir/GameObjects/Obstacles/Wall.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pinball.dir/GameObjects/Obstacles/Wall.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/anon/Desktop/Pinball Khaled Recom/Pinball/GameObjects/Obstacles/Wall.cpp" > CMakeFiles/Pinball.dir/GameObjects/Obstacles/Wall.cpp.i

CMakeFiles/Pinball.dir/GameObjects/Obstacles/Wall.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pinball.dir/GameObjects/Obstacles/Wall.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/anon/Desktop/Pinball Khaled Recom/Pinball/GameObjects/Obstacles/Wall.cpp" -o CMakeFiles/Pinball.dir/GameObjects/Obstacles/Wall.cpp.s

CMakeFiles/Pinball.dir/GameObjects/Flipper.cpp.o: CMakeFiles/Pinball.dir/flags.make
CMakeFiles/Pinball.dir/GameObjects/Flipper.cpp.o: ../GameObjects/Flipper.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/anon/Desktop/Pinball Khaled Recom/Pinball/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Pinball.dir/GameObjects/Flipper.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Pinball.dir/GameObjects/Flipper.cpp.o -c "/home/anon/Desktop/Pinball Khaled Recom/Pinball/GameObjects/Flipper.cpp"

CMakeFiles/Pinball.dir/GameObjects/Flipper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pinball.dir/GameObjects/Flipper.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/anon/Desktop/Pinball Khaled Recom/Pinball/GameObjects/Flipper.cpp" > CMakeFiles/Pinball.dir/GameObjects/Flipper.cpp.i

CMakeFiles/Pinball.dir/GameObjects/Flipper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pinball.dir/GameObjects/Flipper.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/anon/Desktop/Pinball Khaled Recom/Pinball/GameObjects/Flipper.cpp" -o CMakeFiles/Pinball.dir/GameObjects/Flipper.cpp.s

CMakeFiles/Pinball.dir/GameObjects/Obstacles/SpriteWalls.cpp.o: CMakeFiles/Pinball.dir/flags.make
CMakeFiles/Pinball.dir/GameObjects/Obstacles/SpriteWalls.cpp.o: ../GameObjects/Obstacles/SpriteWalls.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/anon/Desktop/Pinball Khaled Recom/Pinball/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Pinball.dir/GameObjects/Obstacles/SpriteWalls.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Pinball.dir/GameObjects/Obstacles/SpriteWalls.cpp.o -c "/home/anon/Desktop/Pinball Khaled Recom/Pinball/GameObjects/Obstacles/SpriteWalls.cpp"

CMakeFiles/Pinball.dir/GameObjects/Obstacles/SpriteWalls.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pinball.dir/GameObjects/Obstacles/SpriteWalls.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/anon/Desktop/Pinball Khaled Recom/Pinball/GameObjects/Obstacles/SpriteWalls.cpp" > CMakeFiles/Pinball.dir/GameObjects/Obstacles/SpriteWalls.cpp.i

CMakeFiles/Pinball.dir/GameObjects/Obstacles/SpriteWalls.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pinball.dir/GameObjects/Obstacles/SpriteWalls.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/anon/Desktop/Pinball Khaled Recom/Pinball/GameObjects/Obstacles/SpriteWalls.cpp" -o CMakeFiles/Pinball.dir/GameObjects/Obstacles/SpriteWalls.cpp.s

CMakeFiles/Pinball.dir/GameObjects/Obstacles/Bumper.cpp.o: CMakeFiles/Pinball.dir/flags.make
CMakeFiles/Pinball.dir/GameObjects/Obstacles/Bumper.cpp.o: ../GameObjects/Obstacles/Bumper.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/anon/Desktop/Pinball Khaled Recom/Pinball/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Pinball.dir/GameObjects/Obstacles/Bumper.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Pinball.dir/GameObjects/Obstacles/Bumper.cpp.o -c "/home/anon/Desktop/Pinball Khaled Recom/Pinball/GameObjects/Obstacles/Bumper.cpp"

CMakeFiles/Pinball.dir/GameObjects/Obstacles/Bumper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pinball.dir/GameObjects/Obstacles/Bumper.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/anon/Desktop/Pinball Khaled Recom/Pinball/GameObjects/Obstacles/Bumper.cpp" > CMakeFiles/Pinball.dir/GameObjects/Obstacles/Bumper.cpp.i

CMakeFiles/Pinball.dir/GameObjects/Obstacles/Bumper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pinball.dir/GameObjects/Obstacles/Bumper.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/anon/Desktop/Pinball Khaled Recom/Pinball/GameObjects/Obstacles/Bumper.cpp" -o CMakeFiles/Pinball.dir/GameObjects/Obstacles/Bumper.cpp.s

CMakeFiles/Pinball.dir/Utility/PixelPerfectCollision.cpp.o: CMakeFiles/Pinball.dir/flags.make
CMakeFiles/Pinball.dir/Utility/PixelPerfectCollision.cpp.o: ../Utility/PixelPerfectCollision.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/anon/Desktop/Pinball Khaled Recom/Pinball/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Pinball.dir/Utility/PixelPerfectCollision.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Pinball.dir/Utility/PixelPerfectCollision.cpp.o -c "/home/anon/Desktop/Pinball Khaled Recom/Pinball/Utility/PixelPerfectCollision.cpp"

CMakeFiles/Pinball.dir/Utility/PixelPerfectCollision.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pinball.dir/Utility/PixelPerfectCollision.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/anon/Desktop/Pinball Khaled Recom/Pinball/Utility/PixelPerfectCollision.cpp" > CMakeFiles/Pinball.dir/Utility/PixelPerfectCollision.cpp.i

CMakeFiles/Pinball.dir/Utility/PixelPerfectCollision.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pinball.dir/Utility/PixelPerfectCollision.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/anon/Desktop/Pinball Khaled Recom/Pinball/Utility/PixelPerfectCollision.cpp" -o CMakeFiles/Pinball.dir/Utility/PixelPerfectCollision.cpp.s

CMakeFiles/Pinball.dir/GameObjects/Manager.cpp.o: CMakeFiles/Pinball.dir/flags.make
CMakeFiles/Pinball.dir/GameObjects/Manager.cpp.o: ../GameObjects/Manager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/anon/Desktop/Pinball Khaled Recom/Pinball/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Pinball.dir/GameObjects/Manager.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Pinball.dir/GameObjects/Manager.cpp.o -c "/home/anon/Desktop/Pinball Khaled Recom/Pinball/GameObjects/Manager.cpp"

CMakeFiles/Pinball.dir/GameObjects/Manager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pinball.dir/GameObjects/Manager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/anon/Desktop/Pinball Khaled Recom/Pinball/GameObjects/Manager.cpp" > CMakeFiles/Pinball.dir/GameObjects/Manager.cpp.i

CMakeFiles/Pinball.dir/GameObjects/Manager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pinball.dir/GameObjects/Manager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/anon/Desktop/Pinball Khaled Recom/Pinball/GameObjects/Manager.cpp" -o CMakeFiles/Pinball.dir/GameObjects/Manager.cpp.s

CMakeFiles/Pinball.dir/Utility/AudioManager.cpp.o: CMakeFiles/Pinball.dir/flags.make
CMakeFiles/Pinball.dir/Utility/AudioManager.cpp.o: ../Utility/AudioManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/anon/Desktop/Pinball Khaled Recom/Pinball/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/Pinball.dir/Utility/AudioManager.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Pinball.dir/Utility/AudioManager.cpp.o -c "/home/anon/Desktop/Pinball Khaled Recom/Pinball/Utility/AudioManager.cpp"

CMakeFiles/Pinball.dir/Utility/AudioManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pinball.dir/Utility/AudioManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/anon/Desktop/Pinball Khaled Recom/Pinball/Utility/AudioManager.cpp" > CMakeFiles/Pinball.dir/Utility/AudioManager.cpp.i

CMakeFiles/Pinball.dir/Utility/AudioManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pinball.dir/Utility/AudioManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/anon/Desktop/Pinball Khaled Recom/Pinball/Utility/AudioManager.cpp" -o CMakeFiles/Pinball.dir/Utility/AudioManager.cpp.s

CMakeFiles/Pinball.dir/Defs.cpp.o: CMakeFiles/Pinball.dir/flags.make
CMakeFiles/Pinball.dir/Defs.cpp.o: ../Defs.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/anon/Desktop/Pinball Khaled Recom/Pinball/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/Pinball.dir/Defs.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Pinball.dir/Defs.cpp.o -c "/home/anon/Desktop/Pinball Khaled Recom/Pinball/Defs.cpp"

CMakeFiles/Pinball.dir/Defs.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pinball.dir/Defs.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/anon/Desktop/Pinball Khaled Recom/Pinball/Defs.cpp" > CMakeFiles/Pinball.dir/Defs.cpp.i

CMakeFiles/Pinball.dir/Defs.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pinball.dir/Defs.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/anon/Desktop/Pinball Khaled Recom/Pinball/Defs.cpp" -o CMakeFiles/Pinball.dir/Defs.cpp.s

CMakeFiles/Pinball.dir/Utility/PreGame.cpp.o: CMakeFiles/Pinball.dir/flags.make
CMakeFiles/Pinball.dir/Utility/PreGame.cpp.o: ../Utility/PreGame.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/anon/Desktop/Pinball Khaled Recom/Pinball/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/Pinball.dir/Utility/PreGame.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Pinball.dir/Utility/PreGame.cpp.o -c "/home/anon/Desktop/Pinball Khaled Recom/Pinball/Utility/PreGame.cpp"

CMakeFiles/Pinball.dir/Utility/PreGame.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pinball.dir/Utility/PreGame.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/anon/Desktop/Pinball Khaled Recom/Pinball/Utility/PreGame.cpp" > CMakeFiles/Pinball.dir/Utility/PreGame.cpp.i

CMakeFiles/Pinball.dir/Utility/PreGame.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pinball.dir/Utility/PreGame.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/anon/Desktop/Pinball Khaled Recom/Pinball/Utility/PreGame.cpp" -o CMakeFiles/Pinball.dir/Utility/PreGame.cpp.s

CMakeFiles/Pinball.dir/Utility/Configurable.cpp.o: CMakeFiles/Pinball.dir/flags.make
CMakeFiles/Pinball.dir/Utility/Configurable.cpp.o: ../Utility/Configurable.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/anon/Desktop/Pinball Khaled Recom/Pinball/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/Pinball.dir/Utility/Configurable.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Pinball.dir/Utility/Configurable.cpp.o -c "/home/anon/Desktop/Pinball Khaled Recom/Pinball/Utility/Configurable.cpp"

CMakeFiles/Pinball.dir/Utility/Configurable.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pinball.dir/Utility/Configurable.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/anon/Desktop/Pinball Khaled Recom/Pinball/Utility/Configurable.cpp" > CMakeFiles/Pinball.dir/Utility/Configurable.cpp.i

CMakeFiles/Pinball.dir/Utility/Configurable.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pinball.dir/Utility/Configurable.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/anon/Desktop/Pinball Khaled Recom/Pinball/Utility/Configurable.cpp" -o CMakeFiles/Pinball.dir/Utility/Configurable.cpp.s

CMakeFiles/Pinball.dir/GameObjects/Obstacles/PopBumper.cpp.o: CMakeFiles/Pinball.dir/flags.make
CMakeFiles/Pinball.dir/GameObjects/Obstacles/PopBumper.cpp.o: ../GameObjects/Obstacles/PopBumper.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/anon/Desktop/Pinball Khaled Recom/Pinball/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/Pinball.dir/GameObjects/Obstacles/PopBumper.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Pinball.dir/GameObjects/Obstacles/PopBumper.cpp.o -c "/home/anon/Desktop/Pinball Khaled Recom/Pinball/GameObjects/Obstacles/PopBumper.cpp"

CMakeFiles/Pinball.dir/GameObjects/Obstacles/PopBumper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pinball.dir/GameObjects/Obstacles/PopBumper.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/anon/Desktop/Pinball Khaled Recom/Pinball/GameObjects/Obstacles/PopBumper.cpp" > CMakeFiles/Pinball.dir/GameObjects/Obstacles/PopBumper.cpp.i

CMakeFiles/Pinball.dir/GameObjects/Obstacles/PopBumper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pinball.dir/GameObjects/Obstacles/PopBumper.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/anon/Desktop/Pinball Khaled Recom/Pinball/GameObjects/Obstacles/PopBumper.cpp" -o CMakeFiles/Pinball.dir/GameObjects/Obstacles/PopBumper.cpp.s

CMakeFiles/Pinball.dir/Utility/PostProcessing.cpp.o: CMakeFiles/Pinball.dir/flags.make
CMakeFiles/Pinball.dir/Utility/PostProcessing.cpp.o: ../Utility/PostProcessing.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/anon/Desktop/Pinball Khaled Recom/Pinball/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/Pinball.dir/Utility/PostProcessing.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Pinball.dir/Utility/PostProcessing.cpp.o -c "/home/anon/Desktop/Pinball Khaled Recom/Pinball/Utility/PostProcessing.cpp"

CMakeFiles/Pinball.dir/Utility/PostProcessing.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pinball.dir/Utility/PostProcessing.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/anon/Desktop/Pinball Khaled Recom/Pinball/Utility/PostProcessing.cpp" > CMakeFiles/Pinball.dir/Utility/PostProcessing.cpp.i

CMakeFiles/Pinball.dir/Utility/PostProcessing.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pinball.dir/Utility/PostProcessing.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/anon/Desktop/Pinball Khaled Recom/Pinball/Utility/PostProcessing.cpp" -o CMakeFiles/Pinball.dir/Utility/PostProcessing.cpp.s

# Object files for target Pinball
Pinball_OBJECTS = \
"CMakeFiles/Pinball.dir/main.cpp.o" \
"CMakeFiles/Pinball.dir/Game.cpp.o" \
"CMakeFiles/Pinball.dir/Interface.cpp.o" \
"CMakeFiles/Pinball.dir/GameObjects/Ball.cpp.o" \
"CMakeFiles/Pinball.dir/GameObjects/Obstacles/Wall.cpp.o" \
"CMakeFiles/Pinball.dir/GameObjects/Flipper.cpp.o" \
"CMakeFiles/Pinball.dir/GameObjects/Obstacles/SpriteWalls.cpp.o" \
"CMakeFiles/Pinball.dir/GameObjects/Obstacles/Bumper.cpp.o" \
"CMakeFiles/Pinball.dir/Utility/PixelPerfectCollision.cpp.o" \
"CMakeFiles/Pinball.dir/GameObjects/Manager.cpp.o" \
"CMakeFiles/Pinball.dir/Utility/AudioManager.cpp.o" \
"CMakeFiles/Pinball.dir/Defs.cpp.o" \
"CMakeFiles/Pinball.dir/Utility/PreGame.cpp.o" \
"CMakeFiles/Pinball.dir/Utility/Configurable.cpp.o" \
"CMakeFiles/Pinball.dir/GameObjects/Obstacles/PopBumper.cpp.o" \
"CMakeFiles/Pinball.dir/Utility/PostProcessing.cpp.o"

# External object files for target Pinball
Pinball_EXTERNAL_OBJECTS =

Pinball: CMakeFiles/Pinball.dir/main.cpp.o
Pinball: CMakeFiles/Pinball.dir/Game.cpp.o
Pinball: CMakeFiles/Pinball.dir/Interface.cpp.o
Pinball: CMakeFiles/Pinball.dir/GameObjects/Ball.cpp.o
Pinball: CMakeFiles/Pinball.dir/GameObjects/Obstacles/Wall.cpp.o
Pinball: CMakeFiles/Pinball.dir/GameObjects/Flipper.cpp.o
Pinball: CMakeFiles/Pinball.dir/GameObjects/Obstacles/SpriteWalls.cpp.o
Pinball: CMakeFiles/Pinball.dir/GameObjects/Obstacles/Bumper.cpp.o
Pinball: CMakeFiles/Pinball.dir/Utility/PixelPerfectCollision.cpp.o
Pinball: CMakeFiles/Pinball.dir/GameObjects/Manager.cpp.o
Pinball: CMakeFiles/Pinball.dir/Utility/AudioManager.cpp.o
Pinball: CMakeFiles/Pinball.dir/Defs.cpp.o
Pinball: CMakeFiles/Pinball.dir/Utility/PreGame.cpp.o
Pinball: CMakeFiles/Pinball.dir/Utility/Configurable.cpp.o
Pinball: CMakeFiles/Pinball.dir/GameObjects/Obstacles/PopBumper.cpp.o
Pinball: CMakeFiles/Pinball.dir/Utility/PostProcessing.cpp.o
Pinball: CMakeFiles/Pinball.dir/build.make
Pinball: CMakeFiles/Pinball.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/anon/Desktop/Pinball Khaled Recom/Pinball/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_17) "Linking CXX executable Pinball"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Pinball.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Pinball.dir/build: Pinball

.PHONY : CMakeFiles/Pinball.dir/build

CMakeFiles/Pinball.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Pinball.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Pinball.dir/clean

CMakeFiles/Pinball.dir/depend:
	cd "/home/anon/Desktop/Pinball Khaled Recom/Pinball/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/anon/Desktop/Pinball Khaled Recom/Pinball" "/home/anon/Desktop/Pinball Khaled Recom/Pinball" "/home/anon/Desktop/Pinball Khaled Recom/Pinball/cmake-build-debug" "/home/anon/Desktop/Pinball Khaled Recom/Pinball/cmake-build-debug" "/home/anon/Desktop/Pinball Khaled Recom/Pinball/cmake-build-debug/CMakeFiles/Pinball.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Pinball.dir/depend

