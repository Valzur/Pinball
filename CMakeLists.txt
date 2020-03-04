cmake_minimum_required(VERSION 3.15)
project(Pinball)

set(CMAKE_CXX_STANDARD 14)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "libs/SFML-2.5.1/lib/cmake/SFML")

find_package(SFML 2.5.1 COMPONENTS graphics audio window system REQUIRED)

include_directories(libs/SFML-2.5.1/include libs/SFML-2.5.1/lib)

add_executable(Pinball main.cpp Game.cpp Game.h Interface.cpp Interface.h GameObjects/Drawable.h GameObjects/Ball.cpp GameObjects/Ball.h GameObjects/Collidable.h Defs.h GameObjects/Obstacles/Obstacle.h GameObjects/Obstacles/Wall.cpp GameObjects/Obstacles/Wall.h GameObjects/Flipper.cpp GameObjects/Flipper.h GameObjects/Obstacles/SpriteWalls.cpp GameObjects/Obstacles/SpriteWalls.h)

target_link_libraries(Pinball sfml-graphics sfml-window sfml-system)