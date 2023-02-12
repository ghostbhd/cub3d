/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrete <ohrete@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:47:15 by abouhmad          #+#    #+#             */
/*   Updated: 2023/01/21 18:45:53 by ohrete           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	*ft_strdup_l(char *s)
{
	char	*p;
	int		i;

	i = 0;
	while (s[i])
		i++;
	p = malloc(sizeof(char) * i + 1);
	if (!p)
		return (0);
	i = 0;
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin_l(char *s1, char *s2)
{
	char	*p;
	int		i;
	int		j;

	i = ft_strlen_l(s1);
	j = ft_strlen_l(s2);
	p = malloc(sizeof(char) * i + j + 1);
	if (!p)
		return (0);
	i = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		p[i + j] = s2[j];
		j++;
	}
	free(s1);
	p[i + j] = '\0';
	return (p);
}

int	ft_strlen_l(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr_l(char *s, int start, int len)
{
	int		i;
	int		lens;
	char	*p;

	if (!s)
		return (0);
	lens = ft_strlen(s);
	if (start >= lens)
		return (ft_strdup_l(""));
	if (lens < start + len)
		len = lens;
	p = malloc(sizeof(char) * len + 1);
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

char	*ft_strchr_l(char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			str = ft_strdup_l(&s[i + 1]);
			free(s);
			return (str);
		}
		i++;
	}
	free(s);
	s = NULL;
	return (NULL);
}
