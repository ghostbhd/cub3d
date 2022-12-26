/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 22:23:35 by abouhmad          #+#    #+#             */
/*   Updated: 2022/12/25 22:18:51 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 1

// struct ----------------------------
typedef struct s_map
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	char	**map;
	int		angle;
}			t_map;

// getline ----------------------------
char		*ft_strdup_l(char *s);
char		*ft_strjoin_l(char *s1, char *s2);
int			ft_strlen_l(char *s);
char		*ft_substr_l(char *s, int start, int len);
char		*ft_strchr_l(char *s, int c);
char		*ft_ret(char *s);
char		*get_next_line(int fd);

// parse ----------------------------
void		ft_parse(int fd, t_map **map);

// utils ----------------------------
void		ft_error(void);

#endif