<center>

# cube3D

![Cub3D](https://i.imgur.com/o6p3z7t.png)

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

![Cub3D](https://i.imgur.com/o6p3z7t.png)

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

- [MiniLibX Documentation](https://harm-smits.github.io/42docs/)
- [Cub3D Documentation](https://harm-smits.github.io/42docs/projects/cub3d)
- [Algorithm Cub3D](https://docs.google.com/document/d/1tdNYHg3Mfqf8dr8W6Ajs3seUugwtmaQizZ7BzimkXog/edit?pli=1#heading=h.bd9zh49nig4r)
- [Cub3D Tutorial](http://forums.mediabox.fr/wiki/tutoriaux/flashplatform/affichage/3d/raycasting)
- [Lode Graphics Tutorial](https://lodev.org/cgtutor/raycasting.html)
- [Wolf Explications](https://guy-grave.developpez.com/tutoriels/jeux/doom-wolfenstein-raycasting/)

## Authors

- [Arthur Ascedu](https://github.com/aascedu)
- [Thea Wang](https://github.com/Zwhea)
