# Pinball
Basic Pinball game coded in C++ as a project for the course, the game engine is built on top of the ![SFML](https://www.sfml-dev.org/) library.
It mainly includes implementations of:
- Bullseye 
- 3 Different Bumpers
- Gates
- Kickers
- Portals
- Magnets
- Lanes
- Score multiplier
- Speed booster
- Switches

## Todo
- The collision detection system for inclined walls is very inaccurate, and thus it's physics system as well
- UI required a bit of refactoring
- Main game loop and architecture requires streamlining as all obstacles can be empowered if given more functionality.

## Installation

Just clone the repo and run the main.cpp file, note that the project is made through cmake and thus working with Visual Studio could be tricky (but definitely possible).
