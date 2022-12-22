/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 22:23:35 by abouhmad          #+#    #+#             */
/*   Updated: 2022/12/22 15:54:03 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "src/libft/libft.h"

#define BUFFER_SIZE 1

// getline ----------------------------
char	*ft_strdup_l(char *s);
char	*ft_strjoin_l(char *s1, char *s2);
int		ft_strlen_l(char *s);
char	*ft_substr_l(char *s, int start, int len);
char	*ft_strchr_l(char *s, int c);
char	*ft_ret(char *s);
void	ft_free(char *s);


typedef struct s_map
{
    char   *no;
    char   *so;
    char   *we;
    char   *ea;
    char	*f;
	char	*c;
	char	**map;
}   t_map;

#endif