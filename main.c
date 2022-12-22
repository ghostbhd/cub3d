/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 22:24:24 by abouhmad          #+#    #+#             */
/*   Updated: 2022/12/23 00:13:59 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

int	main(int ac, char **av)
{
	char	*str;
	int		fd;
	t_map	*map;

	if (ac == 2)
	{
		str = ft_strrchr(av[1], '.');
		if (!str && !ft_strncmp(str, ".cub", 5))
			ft_error();
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			ft_error();
		ft_parse(fd, &map);
	}
}
