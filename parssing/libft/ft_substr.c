/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 22:35:01 by abouhmad          #+#    #+#             */
/*   Updated: 2021/11/20 11:52:06 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	lens;
	char	*p;

	if (!s)
		return (0);
	lens = ft_strlen(s);
	if (start >= lens)
		return (ft_strdup(""));
	if (lens < start + len)
		len = lens;
	p = ft_calloc(len + 1, sizeof(char));
	if (!p)
		return (0);
	i = 0;
	while (s[start + i] && len > 0)
	{
		p[i] = s[start + i];
		i++;
		len--;
	}
	p[i] = '\0';
	return (p);
}
