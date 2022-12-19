/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:15:02 by abouhmad          #+#    #+#             */
/*   Updated: 2021/11/18 16:22:05 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_signe(char c)
{
	if (c == '-')
		return (-1);
	return (1);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	nbr;
	long	tmp;
	int		s;

	i = 0;
	s = 1;
	nbr = 0;
	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		i++;
	s = ft_signe(str[i]);
	if (str[i] == '-' || str[i] == '+')
		i++;
	tmp = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - 48;
		if (nbr < tmp && s == -1)
			return (0);
		if (nbr < tmp)
			return (-1);
		tmp = nbr;
		i++;
	}
	return (nbr * s);
}
