/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 22:23:35 by abouhmad          #+#    #+#             */
/*   Updated: 2023/01/28 00:43:20 by abouhmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 1
# define PI 3.14159265358979323846

// struct ----------------------------

enum			e_texture
{
	NO,
	SO,
	WE,
	EA
};

typedef struct s_texture
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_texture;

typedef struct s_data
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			f[3];
	int			c[3];
	char		**map;
	double		p_x;
	double		p_y;
	double		angle;
	t_texture	*texture[4];
	char		*path[4];
	int			walldir;
	int			is_horz;
	int			is_vert;
	int			i;
	int			j;
	int			height;
	int			width;
	double		turn_dir;
	int			wok_r_l;
	int			wok_up_do;
	double		move;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	float		dx;
	float		dy;
	double		x_inc;
	double		y_inc;
	double		x;
	double		y;
	double		ray_ang;
	double		distance;
	double		save_d;
	int			save_walldir;
	double		size_wall;
	int			r;
	int			len;
	char		*tmp;
	double		sv_ray;
	double		s_x;
	double		s_y;
}				t_data;

// getline ----------------------------
char			*ft_strdup_l(char *s);
char			*ft_strjoin_l(char *s1, char *s2);
int				ft_strlen_l(char *s);
char			*ft_substr_l(char *s, int start, int len);
char			*ft_strchr_l(char *s, int c);
char			*ft_ret(char *s);
char			*get_next_line(int fd);

// parse ----------------------------
void			ft_parse(int fd, t_data **map, char *line);

// check map ------------------------
void			ft_check_map(char **map);
void			ft_get_pos(t_data **map);

// utils ----------------------------
void			ft_error(char *msg);
int				is_wspace(char c);
int				count_char(char *str, char c);
int				n_spc(char *str);
void			ft_free(char **str);

#endif