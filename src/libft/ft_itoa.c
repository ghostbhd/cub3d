/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:28:42 by abouhmad          #+#    #+#             */
/*   Updated: 2021/11/13 22:59:06 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wlen(int n, int s)
{
	int	len;

	len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	if (s < 0)
		return (len + 1);
	return (len);
}

static char	*ft_puts(int len, long nbr, int s)
{
	char	*p;

	p = ft_calloc(len + 1, sizeof(char));
	if (!p)
		return (0);
	p[len] = '\0';
	while (len--)
	{
		ft_memset(p + len, (nbr % 10) + 48, 1);
		nbr /= 10;
	}
	if (s == -1)
		p[0] = '-';
	return (p);
}

char	*ft_itoa(int n)
{
	int		s;
	int		len;
	long	nbr;
	char	*p;

	s = 1;
	nbr = n;
	if (nbr == 0)
		return (ft_strdup("0"));
	if (nbr < 0)
	{
		s = -1;
		nbr *= s;
	}
	len = ft_wlen(nbr, s);
	p = ft_puts(len, nbr, s);
	return (p);
}
