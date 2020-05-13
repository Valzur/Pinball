cmake_minimum_required(VERSION 3.15)
project(Pinball)

set(CMAKE_CXX_STANDARD 14)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "libs/SFML-2.5.1/lib/cmake/SFML")
set(FREETYPE_DIR "libs/freetype-2.10.0/include")
set(Ogg_DIR "libs/libogg-1.3.4/cmake")

find_package(SFML 2.5.1 REQUIRED COMPONENTS audio graphics window system)
find_package(FreeType 2.10.0 )
find_package(Ogg 1.3.4)

include_directories(libs/libogg-1.3.4/include libs/libogg-1.3.4/)
include_directories(libs/flac-1.3.2/include)
include_directories(liboggz-1.1.1/include)
include_directories(libs/freetype-2.10.0/include)
include_directories(libs/SFML-2.5.1/include libs/SFML-2.5.1/lib libs/SFML-2.5.1/bin)

add_executable(Pinball main.cpp Game.cpp Game.h Interface.cpp Interface.h
        GameObjects/Drawable.h GameObjects/Ball.cpp GameObjects/Ball.h GameObjects/Collidable.h
        Defs.h GameObjects/Obstacles/Obstacle.h GameObjects/Obstacles/Wall.cpp GameObjects/Obstacles/Wall.h
        GameObjects/Flipper.cpp GameObjects/Flipper.h GameObjects/Obstacles/SpriteWalls.cpp
        GameObjects/Obstacles/SpriteWalls.h GameObjects/Obstacles/Bumper.cpp GameObjects/Obstacles/Bumper.h
        Utility/PixelPerfectCollision.cpp Utility/PixelPerfectCollision.h GameObjects/Manager.cpp
        GameObjects/Manager.h Utility/AudioManager.cpp Utility/AudioManager.h Defs.cpp Utility/PreGame.cpp
        Utility/PreGame.h Utility/Configurable.cpp Utility/Configurable.h GameObjects/Obstacles/PopBumper.cpp
        GameObjects/Obstacles/PopBumper.h Utility/PostProcessing.cpp Utility/PostProcessing.h GameObjects/Obstacles/Portal.cpp
        GameObjects/Obstacles/Portal.h Utility/CollisionDetection.cpp Utility/CollisionDetection.h GameObjects/Obstacles/Magnet.cpp
        GameObjects/Obstacles/Magnet.h GameObjects/Obstacles/Gate.cpp GameObjects/Obstacles/ExternalFrame.cpp
        GameObjects/Obstacles/InternalFrames.cpp GameObjects/Obstacles/Kicker.cpp
        GameObjects/Obstacles/Collectable.cpp GameObjects/Obstacles/Collectable.h GameObjects/Obstacles/SpeedBooster.cpp
        GameObjects/Obstacles/SpeedBooster.h GameObjects/Obstacles/ThrustBumper.cpp GameObjects/Obstacles/ThrustBumper.h
        GameObjects/Obstacles/VibraniumBumper.cpp GameObjects/Obstacles/VibraniumBumper.h GameObjects/Obstacles/ScoreMultiplier.cpp
        GameObjects/Obstacles/ScoreMultiplier.h GameObjects/Obstacles/Switch.cpp GameObjects/Obstacles/Switch.h GameObjects/Obstacles/Lane.cpp GameObjects/Obstacles/Lane.h)

target_link_libraries(Pinball OpenAL Vorbis)

target_link_libraries(Pinball sfml-audio sfml-graphics sfml-window sfml-system)