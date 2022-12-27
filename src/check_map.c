/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 11:46:02 by abouhmad          #+#    #+#             */
/*   Updated: 2022/12/27 08:02:04 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	is_wspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

void	map_is_valid(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
			{
				if (map[i][j + 1] == ' ' || map[i][j - 1] == ' ' || map[i
					+ 1][j] == ' ' || map[i - 1][j] == ' ')
					ft_error();
			}
			if (map[i][j] == '0')
			{
				if (map[i][j + 1] == ' ' || map[i][j - 1] == ' ' || map[i
					+ 1][j] == ' ' || map[i - 1][j] == ' ')
					ft_error();
			}
		}
	}
}

void	ft_check_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'N'
				&& map[i][j] != 'S' && map[i][j] != 'E' && map[i][j] != 'W'
				&& !is_wspace(map[i][j]))
				ft_error();
			j++;
		}
		i++;
	}
	map_is_valid(map);
}
