/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 22:24:24 by abouhmad          #+#    #+#             */
/*   Updated: 2023/01/03 18:06:24 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

// Test show map parsed ----------------------------
/* void	ft_print_map(t_map *map)
{
	int	i;

	i = -1;
	printf("NO %s\n", map->no);
	printf("SO %s\n", map->so);
	printf("WE %s\n", map->we);
	printf("EA %s\n", map->ea);
	printf("F  ");
	while (++i < 3)
		printf("%3d ", map->f[i]);
	i = -1;
	printf("\nC  ");
	while (++i < 3)
		printf("%3d ", map->c[i]);
	printf("\n");
	i = -1;
	while (map->map[++i])
		printf("%s\n", map->map[i]);
} */
// -------------------------------------------------
float	get_angle(char c)
{
	if (c == 'N')
		return (3 * PI / 2);
	else if (c == 'S')
		return (PI / 2);
	else if (c == 'W')
		return (PI);
	return (0);
}

void	ft_get_pos(t_map **map)
{
	int	j;
	int	i;

	i = -1;
	while ((*map)->map[++i])
	{
		j = -1;
		while ((*map)->map[i][++j])
		{
			if ((*map)->map[i][j] == 'N' || (*map)->map[i][j] == 'S'
				|| (*map)->map[i][j] == 'E' || (*map)->map[i][j] == 'W')
			{
				(*map)->p_x = i;
				(*map)->p_y = j;
				(*map)->angle = get_angle((*map)->map[i][j]);
				(*map)->map[i][j] = '0';
				break ;
			}
		}
	}
}

void	ft_init(t_map **map)
{
	(*map)->no = NULL;
	(*map)->so = NULL;
	(*map)->we = NULL;
	(*map)->ea = NULL;
	(*map)->f[0] = -1;
	(*map)->f[1] = -1;
	(*map)->f[2] = -1;
	(*map)->c[0] = -1;
	(*map)->c[1] = -1;
	(*map)->c[2] = -1;
	(*map)->map = NULL;
	(*map)->p_x = 0;
	(*map)->p_y = 0;
	(*map)->angle = 0;
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
			ft_error("Error\nWrong file extension\n");
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			ft_error("Error\nFile not found\n");
		line = get_next_line(fd);
		ft_init(&map);
		ft_parse(fd, &map, line);
		ft_check_map(map->map);
		ft_get_pos(&map);
	}
	else
		ft_error("Error\nWrong number of arguments\n");
	return (0);
}
// ft_print_map(map); show map parsed
