/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrete <ohrete@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:46:16 by abouhmad          #+#    #+#             */
/*   Updated: 2023/01/21 18:45:58 by ohrete           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

//get line without \n
char	*ft_ret(char *s)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	if (s[i] == '\n')
	{
		str = ft_substr_l(s, 0, i);
		return (str);
	}
	return (ft_strdup_l(s));
}

char	*ft_line(char *str, char *buf, int fd)
{
	int	i;
	int	re;

	i = 0;
	while (str[i] != '\n')
	{
		re = read(fd, buf, BUFFER_SIZE);
		if (re <= 0)
			break ;
		buf[re] = '\0';
		str = ft_strjoin_l(str, buf);
		while (str[i] && str[i] != '\n')
			i++;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buff;
	char		*val;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!str)
		str = ft_strdup_l("");
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	str = ft_line(str, buff, fd);
	free(buff);
	buff = NULL;
	if (str[0] == '\0')
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	val = ft_ret(str);
	str = ft_strchr_l(str, '\n');
	return (val);
}
