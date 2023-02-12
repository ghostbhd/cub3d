/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:10:40 by abouhmad          #+#    #+#             */
/*   Updated: 2021/11/09 15:40:31 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	size_t				i;

	str = (const unsigned char *) s;
	i = 0;
	while (n-- > 0)
	{
		if (str[i] == (unsigned char) c)
			return ((void *)str + i);
		i++;
	}
	return (0);
}
