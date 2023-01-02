/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 23:46:02 by abouhmad          #+#    #+#             */
/*   Updated: 2023/01/02 17:11:45 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

char	*get_text(char *line, int i)
{
	char	*text;

	if (line[i] == ' ')
		ft_error();
	text = ft_strdup(line + i);
	free(line);
	return (text);
}

int	n_spc(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	return (i);
}

int	is_full(t_map **map)
{
	if ((*map)->no && (*map)->so && (*map)->we && (*map)->ea && (*map)->f[0]
		&& (*map)->c[0] && (*map)->map)
		return (1);
	return (0);
}

void	ft_fill_map(int fd, t_map **map, char *line)
{
	int	i;

	i = 0;
	(*map)->map = malloc(sizeof(char *) * 100);
	if (ft_strchr(line, '0'))
		ft_error();
	while (line)
	{
		if (ft_strncmp(line + n_spc(line), "1", 1) == 0)
		{
			(*map)->map[i] = malloc(sizeof(char) * (ft_strlen(line) - 1));
			(*map)->map[i] = ft_strdup(line);
		}
		else
			ft_error();
		i++;
		line = get_next_line(fd);
	}
	(*map)->map[i] = NULL;
	if (ft_strchr((*map)->map[i - 1], '0'))
		ft_error();
}

int count_char(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

void	fill_color(t_map **map, char *str, char c)
{
	int	i;
	int k;

	i = -1;
	k = 0;
	if (count_char(str, ',') != 2)
		ft_error();
	while (str[++i])
	{
		if (ft_isdigit(str[i]))
		{
			if (c == 'F')
				(*map)->f[k] = ft_atoi(str + i);
			else
				(*map)->c[k] = ft_atoi(str + i);
			if (ft_atoi(str + i) > 255)
				ft_error();
			while (ft_isdigit(str[i]))
				i++;
			k++;
		}
	}
	
}

void	ft_parse(int fd, t_map **map, char *line)
{
	int	i;

	i = 0;
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
			;
		else
			ft_error();
		line = get_next_line(fd);
	}
}
