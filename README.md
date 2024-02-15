# cub3D - My first RayCaster with miniLibX

This is a project completed for the subject **cub3d** as part of the curriculum. The goal was to create a simple RayCaster game using the miniLibX library, where the player navigates through a maze rendered in a 3D perspective.

## Project Overview

The project implements the following features:

- Rendering of a 3D maze environment using raycasting techniques.
- Smooth window management, including switching windows and minimizing.
- Display of different wall textures based on the orientation of the wall (North, South, East, West).
- Customizable floor and ceiling colors.
- Controls for movement and viewpoint adjustment:
  - Left and right arrow keys to look left and right.
  - W, A, S, and D keys to move the player's point of view.
- Clean exit from the program upon pressing ESC key or clicking on the window's close button.

## Usage

To run the program, compile it with the provided Makefile:

```
make
```

Then, run the executable providing a scene description file with the `.cub` extension as the first argument:

```
./cub3D path_to_scene.cub
```

## Scene Description File

The scene description file defines the parameters of the game environment. It follows a strict format:

- The map must be enclosed by walls.
- Elements can be separated by one or more empty lines.
- Each type of information for an element is preceded by an identifier and separated by one or more spaces.
- The map must be parsed exactly as it appears in the file, handling spaces as valid parts of the map.
- Example of the scene description file:

```
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture
F 220,100,0
C 225,30,0
1111111111111111111111111
1000000000110000000000001
1011000001110000000000001
1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

## Error Handling

If any misconfiguration is encountered in the scene description file, the program exits with an error message "Error\n" followed by an explicit error message indicating the issue.

## Dependencies

- [miniLibX](https://github.com/42Paris/minilibx-linux) - A simple X-Window (X11R6) programming API in C, designed for students.
- Standard C Library (`libc`)

## Acknowledgments

This project was completed as part of the curriculum and specifications provided by the educational institution.
