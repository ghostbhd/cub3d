/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 23:46:02 by abouhmad          #+#    #+#             */
/*   Updated: 2022/12/23 00:20:46 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

char	*get_text(char *line)
{
	char	*text;
	int		i;

	i = 0;
	if (line[i] == ' ')
		ft_error();
	text = ft_strdup(line);
	return (text);
}

void	ft_parse(int fd, t_map **map)
{
	char	*line;
	int		i;

	i = 0;
	(void) map;
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strncmp(line, "NO ", 3) == 0)
			(*map)->no = get_text(line + 3);
		else if (ft_strncmp(line, "SO ", 3) == 0)
			(*map)->so = get_text(line + 3);
		else if (ft_strncmp(line, "WE ", 3) == 0)
			(*map)->we = get_text(line + 3);
		else if (ft_strncmp(line, "EA ", 3) == 0)
			(*map)->ea = get_text(line + 3);
		else if (ft_strncmp(line, "F ", 2) == 0)
			(*map)->f = get_text(line + 2);
		else if (ft_strncmp(line, "C ", 2) == 0)
			(*map)->c = get_text(line + 2);
		else if (ft_strncmp(line, "1", 1) == 0)
			return ;
		else
			ft_error();
		line = get_next_line(fd);
	}
}