/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 23:46:02 by abouhmad          #+#    #+#             */
/*   Updated: 2023/01/02 23:25:17 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

char	*get_text(char *line, int i)
{
	char	*text;

	if (line[i] == ' ')
		ft_error("Error\nInvalid character after identifier\n");
	text = ft_strdup(line + i);
	free(line);
	return (text);
}

int	is_full(t_map **map)
{
	if ((*map)->no && (*map)->so && (*map)->we && (*map)->ea
		&& (*map)->f[0] != -1 && (*map)->c[0] != -1)
		return (1);
	return (0);
}

void	ft_fill_map(int fd, t_map **map, char *line)
{
	int	i;

	i = 0;
	(*map)->map = malloc(sizeof(char *) * 100);
	if (count_char(line, '0'))
		ft_error("Error\nFirst line of map is not full of walls\n");
	while (line)
	{
		if (line[n_spc(line)] == '1')
		{
			(*map)->map[i] = ft_strdup(line);
			free(line);
			i++;
		}
		else
			ft_error("Error\nMap is not starting with walls\n");
		line = get_next_line(fd);
	}
	(*map)->map[i] = NULL;
	if (count_char((*map)->map[i - 1], '0'))
		ft_error("Error\nLast line of map is not full of walls\n");
}

void	fill_color(t_map **map, char *str, char c)
{
	int	i;
	int	k;

	i = -1;
	k = 0;
	if (count_char(str, ',') != 2)
		ft_error("Error\nInvalid number of colors\n");
	while (str[++i])
	{
		if (ft_isdigit(str[i]) && k < 3)
		{
			if (ft_atoi(str + i) > 255 || ft_atoi(str + i) < 0)
				ft_error("Error\nColor is out of range\n");
			if (c == 'F')
				(*map)->f[k++] = ft_atoi(str + i);
			else
				(*map)->c[k++] = ft_atoi(str + i);
			while (ft_isdigit(str[i]))
				i++;
			if (str[i + n_spc(str + i)] != ','
				&& str[i + n_spc(str + i)] != '\0')
				ft_error("Error\nInvalid number of colors *\n");
		}
	}
	free(str);
}

void	ft_parse(int fd, t_map **map, char *line)
{
	while (line)
	{
		if (ft_strncmp(line, "NO ", 3) == 0)
			(*map)->no = get_text(line, 3);
		else if (ft_strncmp(line, "SO ", 3) == 0)
			(*map)->so = get_text(line, 3);
		else if (ft_strncmp(line, "WE ", 3) == 0)
			(*map)->we = get_text(line, 3);
		else if (ft_strncmp(line, "EA ", 3) == 0)
			(*map)->ea = get_text(line, 3);
		else if (ft_strncmp(line, "F ", 2) == 0)
			fill_color(map, get_text(line, 2), 'F');
		else if (ft_strncmp(line, "C ", 2) == 0)
			fill_color(map, get_text(line, 2), 'C');
		else if (ft_strncmp(line + n_spc(line), "1", 1) == 0 && is_full(map))
			ft_fill_map(fd, map, line);
		else if (line[n_spc(line)] == '\0')
			free(line);
		else
			ft_error("Error\nInvalid identifier\n");
		line = get_next_line(fd);
	}
}
