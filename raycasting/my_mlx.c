/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:28:25 by ohrete            #+#    #+#             */
/*   Updated: 2023/01/28 00:44:15 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	reset_image(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img);
	data->img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
}

void	show_window(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	mouse_hook(int x, int y, t_data *data)
{
	(void)y;
	if (x > 0 && x < WIDTH / 2 - 4 && y > 0 && y < HEIGHT)
		key_down(KEY_LEFT, data);
	else if (x < WIDTH && x > WIDTH / 2 + 4 && x > 0 && y > 0 && y < HEIGHT)
		key_down(KEY_RIGHT, data);
	return (0);
}

void	create_window(t_data *data)
{
	data->wok_r_l = 0;
	data->wok_up_do = 0;
	data->turn_dir = 0;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "CUB3D XD");
	data->img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	init_textures(data);
	drawing(data);
	mlx_hook(data->win_ptr, 2, 0, key_down, data);
	mlx_hook(data->win_ptr, 17, 0, ft_exit, data);
	mlx_hook(data->win_ptr, 6, 0, mouse_hook, data);
	mlx_loop(data->mlx_ptr);
}
