/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:42:55 by ohrete            #+#    #+#             */
/*   Updated: 2023/01/28 01:09:34 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../parssing/header.h"
# include <math.h>
# include <mlx.h>
# include <string.h>

# define HEIGHT 1200
# define WIDTH 1200
# define KEY_ESC 53
# define KEY_C 8
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_A 0
# define KEY_D 2
# define KEY_S 1
# define KEY_W 13
# define SPEED 0.4
# define TURN_SPEED 0.15
# define NUM_RAYS 1200

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
	SCALE = 64,
	PLYR_SIZE = SCALE / 5,
	WHITE = 0x00ffffff,
	BLACK = 0x00000000,
	RED = 0x00ff0000,
	GREEN = 0x0000ff00,
	BLUE = 0x000000ff,
	CYAN = 0x00ABCDEF,
	CREAMY = 0x00FEDCBA,
	PISTASH = 0x00DCFEBA,
	YELLOW = 0xFFFF00,
	BROWN = 0x964B00,
};

////////Minilibx/////////////
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	show_window(t_data *data);
void	create_window(t_data *data);

//////////Event////////////////
void	moving(t_data *data);
int		key_down(int key, t_data *data);
int		ft_exit(void);

/////////Drawing/////////////
void	reset_image(t_data *data);
// void	draw_with_pixels(t_data *data, double x0, double y0, int size,
// 			int color);
void	draw_map(t_data *data);
void	draw_player(t_data *data, int color);
int		has_wall(t_data *data, int x, int y);
int		drawing(t_data *data);

/////////textures/////////////
// void	init_path(t_data *data);
void	init_textures(t_data *data);
int		get_colors(t_texture *texture, double x_of_img, int i,
			double size_wall);
void	draw_ceiling(t_data *data, int x_ray, double top);
void	draw_floor(t_data *data, int x_ray, double top);

/////////DDA ALGO/////////////
double	dda_algo(t_data *data, double X1, double Y1);
void	my_rays(t_data *data);
void	get_walldir(t_data *data);

#endif