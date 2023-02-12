/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:18:23 by abouhmad          #+#    #+#             */
/*   Updated: 2023/01/28 00:47:18 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_textures(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 4)
		data->texture[i] = malloc(sizeof(t_texture));
	i = -1;
	data->path[NO] = data->no;
	data->path[SO] = data->so;
	data->path[WE] = data->we;
	data->path[EA] = data->ea;
	while (++i < 4)
	{
		if (data->texture[i] == NULL)
			ft_error("Error\nMalloc failed");
		data->texture[i]->img = mlx_xpm_file_to_image(data->mlx_ptr,
				data->path[i], &data->texture[i]->width,
				&data->texture[i]->height);
		if (data->texture[i]->img == NULL)
			ft_error("Error\nTexture not found");
		data->texture[i]->addr = mlx_get_data_addr(data->texture[i]->img,
				&data->texture[i]->bits_per_pixel, &data->texture[i]
				->line_length, &data->texture[i]->endian);
		if (data->texture[i]->addr == NULL)
			ft_error("Error\nTexture not found");
	}
}

int	get_colors(t_texture *texture, double x_of_img, int i, double size_wall)
{
	int		x;
	int		y;
	char	*addr;

	x = (int)(x_of_img * texture->width / SCALE) % texture->width;
	y = (int)(i * (texture->height / size_wall)) % texture->height;
	addr = texture->addr + (y * texture->line_length + x
			* (texture->bits_per_pixel / 8));
	return (*(unsigned int *)addr);
}

void	get_walldir(t_data *data)
{
	int	x;

	x = data->x - data->x_inc;
	if (has_wall(data, x / SCALE, data->y / SCALE))
	{
		if (data->ray_ang >= PI && data->ray_ang <= 2 * PI)
			data->walldir = NO;
		else if (data->ray_ang >= 0 && data->ray_ang <= PI)
			data->walldir = SO;
	}
	else
	{
		if (data->ray_ang >= PI / 2 && data->ray_ang < 3 * PI / 2)
			data->walldir = WE;
		else if (data->ray_ang >= 3 * PI / 2 || data->ray_ang < PI / 2)
			data->walldir = EA;
	}
}

void	draw_ceiling(t_data *data, int x_ray, double top)
{
	int	i;

	i = -1;
	while (++i < top)
		my_mlx_pixel_put(data, x_ray, i, data->c[0] * 256 * 256 + data->c[1]
			* 256 + data->c[2]);
}

void	draw_floor(t_data *data, int x_ray, double top)
{
	int	i;

	i = top - 1;
	while (++i < HEIGHT)
		my_mlx_pixel_put(data, x_ray, i, data->f[0] * 256 * 256 + data->f[1]
			* 256 + data->f[2]);
}
