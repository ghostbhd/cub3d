# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abouhmad <abouhmad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/06 16:05:18 by abouhmad          #+#    #+#              #
#    Updated: 2022/10/09 20:13:29 by abouhmad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = @gcc -c

AR = @ar -rc

CFLAGS = -Wall -Wextra -Werror

RM = @rm -f

SRCS =	ft_bzero.c\
        ft_isalpha.c\
        ft_isdigit.c\
        ft_isascii.c\
        ft_isalnum.c\
        ft_isprint.c\
        ft_memcpy.c\
        ft_memmove.c\
        ft_memset.c\
        ft_strlcat.c\
        ft_strlcpy.c\
        ft_strlen.c\
        ft_toupper.c\
        ft_tolower.c\
        ft_strchr.c\
        ft_strrchr.c\
        ft_strncmp.c\
        ft_memchr.c\
        ft_memcmp.c\
        ft_strnstr.c\
        ft_atoi.c\
        ft_calloc.c\
        ft_strdup.c\
        ft_substr.c\
        ft_strjoin.c\
        ft_strtrim.c\
        ft_split.c\
        ft_itoa.c\
        ft_strmapi.c\
        ft_striteri.c\
        ft_putchar_fd.c\
        ft_putstr_fd.c\
        ft_putendl_fd.c\
        ft_putnbr_fd.c
    
BON = ft_lstnew_bonus.c\
        ft_lstadd_front_bonus.c\
        ft_lstsize_bonus.c\
        ft_lstlast_bonus.c\
        ft_lstadd_back_bonus.c\
        ft_lstdelone_bonus.c\
        ft_lstclear_bonus.c\
        ft_lstiter_bonus.c\
        ft_lstmap_bonus.c\

OBJS = ${subst .c,.o,${SRCS}}

OBJSBON = ${subst .c,.o,${BON}}

all :  ${NAME}

${NAME} : ${OBJS}
	${AR} ${NAME} ${OBJS}

bonus : ${OBJSBON}

${OBJSBON} : ${BON}
	${AR} ${NAME} ${OBJSBON}

clean :
	${RM} ${OBJS} ${OBJSBON}
fclean : clean
	${RM} ${NAME}
re : fclean all
