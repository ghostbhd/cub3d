/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 22:24:24 by abouhmad          #+#    #+#             */
/*   Updated: 2022/12/29 18:50:32 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

void	ft_print_map(t_map *map)
{
	int	i;

	i = 0;
	printf("NO %s\n", map->no);
	printf("SO %s\n", map->so);
	printf("WE %s\n", map->we);
	printf("EA %s\n", map->ea);
	printf("F %s\n", map->f);
	printf("C %s\n", map->c);
	while (map->map[i])
	{
		printf("%s\n", map->map[i]);
		i++;
	}
}

void	ft_get_pos(t_map **map)
{
	int	j;
	int	i;

	i = 0;
	while ((*map)->map[i])
	{
		j = 0;
		while ((*map)->map[i][j])
		{
			if ((*map)->map[i][j] == 'N' || (*map)->map[i][j] == 'S'
				|| (*map)->map[i][j] == 'E' || (*map)->map[i][j] == 'W')
			{
				(*map)->p_x = i;
				(*map)->p_y = j;
				if ((*map)->map[i][j] == 'N')
					(*map)->angle = 3 * PI / 2;
				else if ((*map)->map[i][j] == 'S')
					(*map)->angle = PI / 2;
				else if ((*map)->map[i][j] == 'E')
					(*map)->angle = 0;
				else if ((*map)->map[i][j] == 'W')
					(*map)->angle = PI;
				(*map)->map[i][j] = '0';
				break ;
			}
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	char	*str;
	char	*line;
	int		fd;
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (ac == 2)
	{
		str = ft_strrchr(av[1], '.');
		if (!str && !ft_strncmp(str, ".cub", 5))
			ft_error();
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			ft_error();
		line = get_next_line(fd);
		ft_parse(fd, &map, line);
		ft_check_map(map->map);
		ft_get_pos(map);
		ft_print_map(map);
	}
}

// white space 
// split RGB
// check if the map is closed