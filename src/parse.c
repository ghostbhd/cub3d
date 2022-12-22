/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 23:46:02 by abouhmad          #+#    #+#             */
/*   Updated: 2022/12/23 00:01:22 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	ft_parse(int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strncmp(line, "R ", 2) == 0)
			i++;
		else if (ft_strncmp(line, "NO ", 3) == 0)
			i++;
		else if (ft_strncmp(line, "SO ", 3) == 0)
			i++;
		else if (ft_strncmp(line, "WE ", 3) == 0)
			i++;
		else if (ft_strncmp(line, "EA ", 3) == 0)
			i++;
		else if (ft_strncmp(line, "S ", 2) == 0)
			i++;
		else if (ft_strncmp(line, "F ", 2) == 0)
			i++;
		else if (ft_strncmp(line, "C ", 2) == 0)
			i++;
		else if (ft_strncmp(line, "1", 1) == 0)
			i++;
		else if (ft_strncmp(line, " ", 1) == 0)
			i++;
		else
			return (-1);
		line = get_next_line(fd);
	}
	return (i);
}