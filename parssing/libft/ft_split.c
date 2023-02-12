/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 13:23:32 by abouhmad          #+#    #+#             */
/*   Updated: 2021/11/20 11:52:38 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(const char *s1, size_t n)
{
	char	*str;
	size_t	i;
	size_t	len;

	len = ft_strlen(s1);
	str = ft_calloc(n + 1, sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (i < n)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

static void	ft_free(char **s, size_t i)
{
	while (i)
		free(s[i--]);
	free(s);
}

static size_t	ft_len(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	**ft_word(char *s, size_t wc, char c, size_t len)
{
	size_t	j;
	size_t	i;
	char	**p;

	j = 0;
	i = 0;
	p = ft_calloc(wc + 1, sizeof(char *));
	if (!p)
		return (0);
	while (j < wc)
	{
		while (s[i] && s[i] == c)
			i++;
		len = ft_len(s + i, c);
		p[j] = ft_strndup(s + i, len);
		if (!p[j])
		{
			ft_free(p, j - 1);
			return (0);
		}
		i += len;
		j++;
	}
	p[wc] = NULL;
	return (p);
}

char	**ft_split(char const *str, char c)
{
	char	**p;
	size_t	i;
	size_t	wc;
	size_t	h;

	if (!str)
		return (0);
	i = 0;
	wc = 0;
	while (str[i] == c && str[i])
		i++;
	h = i;
	while (str[i])
	{
		if (str[i] != c)
		{
			while (str[i] != c && str[i + 1])
				i++;
			wc++;
		}
		i++;
	}
	p = ft_word((char *) str + h, wc, c, 0);
	return (p);
}
