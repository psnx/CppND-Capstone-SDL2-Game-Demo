# Udacity C++ Nanodegree Program - Capstone
This is a simple demonstration of a basic game utilizing the SDL Framework.
The goal is to demonstrate how one can make a simple game engine.
The game itself is an overly simple implementation of a tile tennis. 
The game is probably not possible to win at this stage as the balls path is completely deterministic and does not visit all the regions of the screen in reasonable time.

## Dependencies
### SDL2
SDL2 works out-of-the box with `vcpkg`, and this is the recommended way of installing it for painless cross-platform build. Follow the installation instructions to install it on your system:
[vcpkg on Github](https://github.com/microsoft/vcpkg)  

As a side note, you may be able to install it with your package manager on Unix-like systems:
```bash
brew install vcpkg # MacOS
```
Once `vcpkg` is installed it can install SDL2 for you:
```bash
vcpkg install sdl2
```
This project was developed and tesed on MacOS 10.15.6 (Catalina)  

## Build
1. Clone or download this repo.
2. Make a folder int the project root and build it from there
```bash
mkdir build && cd build # build folder
cmake .. && make        # build
./Capostone             # run it
```
## Features overview
This is a demonstration of how you can make a simple game engine using only SDL.  The engine itself is rather
simple nevertheless it implements the following features:

- A timed game loop that ensures the calling of the `GameObject`'s `Update()` and `Draw()` methods.
- An easy way to register a  `gameObject`, which is being updated and drawn then by the _enginge_
- A simple collision detection mechanism
- Input reader to process the users input.

Please study the comments provided in the header files in the `include folder` for further reference.

## Acknowledgements

The codebase is inspired by [Udacity's CppND Snake Game](https://github.com/udacity/CppND-Capstone-Snake-Game), especially the render function and the game loop.  

## Useful links
- [SDL](https://www.libsdl.org)
- [Lazy Foo's Productions](https://lazyfoo.net/tutorials/SDL/index.php)

