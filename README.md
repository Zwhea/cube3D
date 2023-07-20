<center>

# cube3D

![Cub3D](https://your_image_url.png)

This project is part of the 42 school curriculum and aims to recreate a game engine using raycasting to simulate a 3D environment in the style of old-school first-person view games.

</center>

## Table of Contents

- [About](#about)
- [Features](#features)
- [Screenshots](#screenshots)
- [Usage](#usage)
- [Controls](#controls)
- [Resources](#resources)
- [Authors](#authors)

## About

Cub3D is a project that challenges you to create a simple 3D game engine from scratch using the C programming language and the MiniLibX (graphical library).

The main objective is to create a maze-like 3D environment where the player can navigate. The project involves implementing a raycasting algorithm to determine the distance and direction of objects in the game world, allowing the creation of the 3D illusion.

## Features

- A player can move within the 3D maze using the arrow keys.
- Walls and other obstacles are textured to give a 3D appearance.
- The player can rotate the camera to look around.
- The game displays a HUD (Heads-Up Display) showing relevant information such as the player's position, direction, and frame rate.
- The game includes a sprite feature, allowing you to render objects with different depths in the 3D environment.

## Screenshots

[To do]


## Usage

### Instructions

**1. Compiling & Executing the program**

To compile and execute the program, run:

```shell
$ make
$ ./cub3D map.cub
```
Replace `map.cub` with the path to your custom map file. The map file defines the layout of the 3D environment, including the textures, sprite positions, and player starting position.

**2. Special Compiling Rules**

To compile the program with fsanitize, run:

```shell
$ make debug
$ ./minishell
```
To compile the program with valgrind, run:

```shell
$ make leaks
```

## Controls

- `↑` : Move forward.
- `↓` : Move backward.
- `←` : Move left.
- `→` : Move right.

## Resources

- [MiniLibX Documentation](https://github.com/42Paris/minilibx-linux)

## Authors

- [Thea Wang](https://github.com/Zwhea)
- [Arthur Ascedu](https://github.com/aascedu)
