/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:25:35 by ohrete            #+#    #+#             */
/*   Updated: 2023/01/28 00:43:46 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	has_wall(t_data *data, int x, int y)
{
	if (x < 0 || y > data->len || y < 0 || x > (int)ft_strlen(data->map[y]))
		return (1);
	else if (data->map[y][x] == '0')
		return (0);
	return (1);
}

double	check_d(t_data *data)
{
	if (data->save_walldir == NO || data->save_walldir == WE)
		return (-2);
	return (2);
}

void	moving(t_data *data)
{
	double	check;
	int		turn;
	int		flag;

	flag = 0;
	check = 0;
	data->move = data->wok_up_do * SPEED;
	data->angle = data->angle + TURN_SPEED * data->turn_dir;
	if (data->wok_r_l)
	{
		check = PI / 2;
		data->move = data->wok_r_l * SPEED;
	}
	data->s_x = (data->p_x + (cos(data->angle + check) * data->move)) * SCALE;
	data->s_y = (data->p_y + (sin(data->angle + check) * data->move)) * SCALE;
	turn = check_d(data);
	if (data->save_walldir == NO || data->save_walldir == SO)
		flag = has_wall(data, data->s_x / SCALE, (data->s_y + turn) / SCALE);
	else
		flag = has_wall(data, (data->s_x + turn) / SCALE, data->s_y / SCALE);
	if (!flag)
	{
		data->p_x = data->s_x / SCALE;
		data->p_y = data->s_y / SCALE;
	}
}

int	ft_exit(void)
{
	exit(0);
}

int	key_down(int key, t_data *data)
{
	if (key == KEY_ESC)
		ft_exit();
	if (key == KEY_D)
		data->wok_r_l = 1;
	else if (key == KEY_A)
		data->wok_r_l = -1;
	if (key == KEY_S || key == KEY_DOWN)
		data->wok_up_do = -1;
	else if (key == KEY_W || key == KEY_UP)
		data->wok_up_do = 1;
	if (key == KEY_RIGHT)
		data->turn_dir = 1;
	else if (key == KEY_LEFT)
		data->turn_dir = -1;
	drawing(data);
	data->wok_r_l = 0;
	data->wok_up_do = 0;
	data->turn_dir = 0;
	return (0);
}
