/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 23:19:29 by abouhmad          #+#    #+#             */
/*   Updated: 2021/11/13 23:51:51 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		lens1;
	int		lens2;
	char	*p;

	if (!s1 || !s2)
		return (0);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	p = ft_calloc(lens1 + lens2 + 1, sizeof(char));
	if (!p)
		return (0);
	ft_memcpy(p, s1, lens1);
	ft_memcpy(p + lens1, s2, lens2);
	p[lens1 + lens2] = '\0';
	return (p);
}
