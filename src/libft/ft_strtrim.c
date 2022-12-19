/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 23:38:23 by abouhmad          #+#    #+#             */
/*   Updated: 2021/11/18 13:05:58 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	int		i;
	int		j;
	int		len;

	if (!s1)
		return (0);
	len = ft_strlen(s1);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]) != 0)
		i++;
	while (s1[len - 1] && len && ft_strchr(set, s1[len - 1]) != 0)
		len--;
	j = len - i;
	if (j <= 0)
		j = 1;
	p = ft_calloc(j + 1, sizeof(char));
	if (!p)
		return (0);
	ft_memcpy(p, s1 + i, j);
	p[j + 1] = '\0';
	return (p);
}
