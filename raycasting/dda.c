/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:37:32 by ohrete            #+#    #+#             */
/*   Updated: 2023/01/28 00:42:07 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	generate_steps(t_data *data)
{
	double	x;
	double	y;

	x = fabs(data->dx);
	y = fabs(data->dy);
	if (x > y)
		return (x);
	return (y);
}

double	distance(t_data *data, double X, double Y)
{
	return (sqrt(pow(X - (data->p_x * SCALE), 2) + pow(Y - (data->p_y * SCALE),
				2)) * 1.0 * cos(data->angle - data->ray_ang));
}

void	render_walls(t_data *data, double d, int x_ray)
{
	double	size_wall;
	double	top;

	size_wall = HEIGHT / d * SCALE;
	top = (HEIGHT / 2.0) - (size_wall / 2.0);
	draw_ceiling(data, x_ray, top);
	data->r = 0;
	while (data->r < size_wall)
	{
		if (data->walldir == NO)
			my_mlx_pixel_put(data, x_ray, top, get_colors(data->texture[NO],
					data->x, data->r, size_wall));
		else if (data->walldir == SO)
			my_mlx_pixel_put(data, x_ray, top, get_colors(data->texture[SO],
					data->x, data->r, size_wall));
		else if (data->walldir == EA)
			my_mlx_pixel_put(data, x_ray, top, get_colors(data->texture[EA],
					data->y, data->r, size_wall));
		else if (data->walldir == WE)
			my_mlx_pixel_put(data, x_ray, top, get_colors(data->texture[WE],
					data->y, data->r, size_wall));
		top++;
		data->r++;
	}
	draw_floor(data, x_ray, top);
}

double	dda_algo(t_data *data, double X1, double Y1)
{
	int	steps;

	data->dx = X1 - data->p_x;
	data->dy = Y1 - data->p_y;
	steps = generate_steps(data);
	data->x_inc = data->dx / steps;
	data->y_inc = data->dy / steps;
	data->x = data->p_x * SCALE;
	data->y = data->p_y * SCALE;
	while (!has_wall(data, data->x / SCALE, data->y / SCALE))
	{
		data->x += data->x_inc / 6;
		data->y += data->y_inc / 6;
	}
	data->save_d = distance(data, data->x, data->y);
	return (data->save_d);
}
/*my_mlx_pixel_put(data, data->x / 4, data->y / 4, RED);*/

void	my_rays(t_data *data)
{
	int	i;

	i = 0;
	data->ray_ang = data->angle - (PI / 6);
	while (i < NUM_RAYS)
	{
		dda_algo(
			data,
			(cos(data->ray_ang) * 64 * SCALE),
			(sin(data->ray_ang) * 64 * SCALE));
		get_walldir(data);
		if (i == (NUM_RAYS / 2 - 1))
			data->save_walldir = data->walldir;
		render_walls(data, data->save_d, i);
		data->ray_ang += PI / 3 / NUM_RAYS;
		if (data->ray_ang < 0)
			data->ray_ang += 2 * PI;
		else if (data->ray_ang > 2 * PI)
			data->ray_ang -= 2 * PI;
		i++;
	}
}
