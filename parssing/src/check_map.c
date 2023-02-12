/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrete <ohrete@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 11:46:02 by abouhmad          #+#    #+#             */
/*   Updated: 2023/01/26 19:01:06 by ohrete           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	map_is_valid(char **map)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '0' && (map[i][j + 1] == ' '
			|| map[i][j - 1] == ' ' || map[i + 1][j] == ' '
			|| map[i - 1][j] == ' ' || !map[i][j + 1]))
				ft_error("Error\nMap is not closed\n");
			if (map[i][j] == '0' && (map[i - 1][j] == '\0'
			|| map[i + 1][j] == '\0'))
				ft_error("Error\nMap is not closed\n");
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
				count++;
		}
	}
	if (count != 1)
		ft_error("Error\nMultiple player positions\n");
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
				ft_error("Error\nInvalid map\n");
			j++;
		}
		i++;
	}
	map_is_valid(map);
}
