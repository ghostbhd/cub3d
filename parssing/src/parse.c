/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 23:46:02 by abouhmad          #+#    #+#             */
/*   Updated: 2023/01/28 00:37:34 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	*get_text(char *line, int i)
{
	char	*text;

	if (line[i] == ' ')
		ft_error("Error\nInvalid character after identifier\n");
	text = ft_strdup(line + i);
	free(line);
	return (text);
}

int	is_full(t_data **map)
{
	if ((*map)->no && (*map)->so && (*map)->we && (*map)->f[0] != -1
		&& (*map)->ea && (*map)->c[0] != -1)
		return (1);
	return (0);
}

void	ft_fill_map(int fd, t_data **map, char *line)
{
	int	i;

	i = 0;
	(*map)->map = malloc(sizeof(char *) * 100);
	if (count_char(line, '0'))
		ft_error("Error\nFirst line of map is not full of walls\n");
	while (line)
	{
		if (line[n_spc(line)] == '1')
			(*map)->map[i++] = ft_strdup(line);
		else if (n_spc(line) > 0 && line[n_spc(line)] == '\0')
			(*map)->map[i++] = ft_strdup(line);
		else
			ft_error("Error\nMap is not starting with walls\n");
		free(line);
		line = get_next_line(fd);
	}
	(*map)->map[i] = NULL;
	if (count_char((*map)->map[i - 1], '0'))
		ft_error("Error\nLast line of map is not full of walls\n");
}

void	fill_color(t_data **map, char *str, char c)
{
	int		i;
	char	**color;

	i = -1;
	if (count_char(str, ',') != 2)
		ft_error("Error\nInvalid number of colors\n");
	while (str[++i])
		if (str[i] != ',' && !ft_isdigit(str[i]) && str[i] != ' ')
			ft_error("Error\nInvalid color\n");
	color = ft_split(str, ',');
	i = -1;
	while (color[++i])
	{
		(*map)->tmp = ft_strtrim(color[i], " ");
		if (ft_atoi((*map)->tmp) < 0 || ft_atoi((*map)->tmp) > 255)
			ft_error("Error\nInvalid color\n");
		if (c == 'F')
			(*map)->f[i] = ft_atoi((*map)->tmp);
		else
			(*map)->c[i] = ft_atoi((*map)->tmp);
		free((*map)->tmp);
	}
	ft_free(color);
	free(str);
}

void	ft_parse(int fd, t_data **map, char *line)
{
	while (line)
	{
		if (ft_strncmp(line, "NO ", 3) == 0 && !(*map)->no)
			(*map)->no = get_text(line, 3);
		else if (ft_strncmp(line, "SO ", 3) == 0 && !(*map)->so)
			(*map)->so = get_text(line, 3);
		else if (ft_strncmp(line, "WE ", 3) == 0 && !(*map)->we)
			(*map)->we = get_text(line, 3);
		else if (ft_strncmp(line, "EA ", 3) == 0 && !(*map)->ea)
			(*map)->ea = get_text(line, 3);
		else if (ft_strncmp(line, "F ", 2) == 0 && (*map)->f[0] == -1)
			fill_color(map, get_text(line, 2), 'F');
		else if (ft_strncmp(line, "C ", 2) == 0 && (*map)->c[0] == -1)
			fill_color(map, get_text(line, 2), 'C');
		else if (ft_strncmp(line + n_spc(line), "1", 1) == 0 && is_full(map))
			ft_fill_map(fd, map, line);
		else if (line[n_spc(line)] == '\0')
			free(line);
		else
			ft_error("Error\nSomething is Missed\n");
		line = get_next_line(fd);
	}
	if (!(*map)->map)
		ft_error("Error\nMap is missing\n");
}
