cmake_minimum_required(VERSION 3.15)
project(Pinball)

set(CMAKE_CXX_STANDARD 14)


add_executable(Pinball main.cpp Game.cpp Game.h Interface.cpp Interface.h
        GameObjects/Drawable.h GameObjects/Ball.cpp GameObjects/Ball.h GameObjects/Collidable.h
        Defs.h GameObjects/Obstacles/Obstacle.h GameObjects/Obstacles/Wall.cpp GameObjects/Obstacles/Wall.h
        GameObjects/Flipper.cpp GameObjects/Flipper.h GameObjects/Obstacles/SpriteWalls.cpp
        GameObjects/Obstacles/SpriteWalls.h GameObjects/Obstacles/Bumper.cpp GameObjects/Obstacles/Bumper.h
        Utility/PixelPerfectCollision.cpp Utility/PixelPerfectCollision.h GameObjects/Manager.cpp
        GameObjects/Manager.h Utility/AudioManager.cpp Utility/AudioManager.h Defs.cpp Utility/PreGame.cpp Utility/PreGame.h Utility/Configurable.cpp Utility/Configurable.h GameObjects/Obstacles/PopBumper.cpp GameObjects/Obstacles/PopBumper.h)

target_link_libraries(Pinball openal vorbis FLAC)

target_link_libraries(Pinball sfml-audio sfml-graphics sfml-window sfml-system)