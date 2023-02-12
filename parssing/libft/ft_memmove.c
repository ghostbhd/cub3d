/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 20:25:53 by abouhmad          #+#    #+#             */
/*   Updated: 2021/11/08 17:28:21 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dst;
	s = src;
	if (!dst && !src)
		return (0);
	if (dst > src)
	{
		while (len-- > 0)
		{
			d[len] = s[len];
		}
	}
	else
	{
		while (len-- > 0)
		{
			*d++ = *s++;
		}
	}
	return (dst);
}
