/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:16:40 by ohrete            #+#    #+#             */
/*   Updated: 2023/01/28 00:02:16 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_player(t_data *data, int color)
{
	my_mlx_pixel_put(data, data->p_x * SCALE / 2, data->p_y * SCALE / 2, color);
}

int	drawing(t_data *data)
{
	reset_image(data);
	moving(data);
	draw_player(data, YELLOW);
	my_rays(data);
	show_window(data);
	return (0);
}
