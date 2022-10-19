# :crystal_ball:	So_Long

In this project, we'll code a simple 2D game to get familiar with the **mlx library**.<br />
For the graphics part of the project we used a library called minilibx. It's fairly basic and somewhat limited, but was still fun to use in the project.

## Game Rules
The game we choose must follow a set of rules. The executable so_long will receive a map as the only argument, and this map will have a **.ber** filetype.

The file also must follow these rules:

Only P (gamer), 1 (wall), 0 (empty), C (collectible), and E (exit) will be accepted characters in our map.<br />
-The map must be rectangular, i.e. all rows must have the same length.<br />
-There must be at least one exit, one player, and one collectible on the map.<br />
-The map must be closed, i.e. surrounded by walls.<br />
-If any of these checks fail, the game must end with Error\n followed by a custom message.<br />

The goal is for the player(s) to collect all the collectibles on the map before going to an exit in the least possible number of steps.

## :computer: USAGE

:warning: Please check that you have mlxlib installed in your machine.

### Run **make**.<br />
### ./so_long mymap.ber.

## HOW TO PLAY
The player’s goal is to collect all collectibles present on the map then escape with minimal movement.

|KEYBOARD|	ACTION|
|--------|--------|
|W, ↑	|Move up|
|S, ↓	|Move down|
|A, ←	|Move left|
|D, →	|Move right|
|ESC ⎋	|Close the game window|
