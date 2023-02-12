/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:50:23 by abouhmad          #+#    #+#             */
/*   Updated: 2021/11/10 11:03:17 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t loc)
{
	size_t	i;
	size_t	j;
	size_t	lenl;

	lenl = ft_strlen(needle);
	i = 0;
	if (needle[i] == '\0')
		return ((char *) haystack);
	while (haystack[i] && loc >= i + lenl)
	{
		j = 0;
		while (haystack[i + j] == needle[j])
		{
			if (needle[j + 1] == '\0')
				return ((char *) haystack + i);
			j++;
		}
		i++;
	}
	return (0);
}
