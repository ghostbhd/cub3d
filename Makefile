SRCS =	main.c src/*.c

CC = @cc

CFLAGS = -Wall -Wextra -Werror

RM = @rm -rf

AR = @ar -rc

NAME = cub

LIB = libft/libft.a

sanitize = -fsanitize=address -g && echo "\x1b[36m \n\t-fsanitize=thread:\x1b[32m Used 💥\n"

all : $(NAME)

$(NAME) : ${SRCS}
	cd libft && make
	${CC} -pthread ${CFLAGS} $(SRCS) $(LIB) -o $(NAME)
	@echo "\x1b[32m \x1b[1m \n✅\tMandatory Compele Success\n\t\x1b[0mPrograme name -\x1b[33m ($(NAME))\n\x1b[0m"

clean :
	cd libft && make clean
#	@echo "\x1b[31m \x1b[1m \n✅\tDelete [$(NAME)] \x1b[32mSuccess\n\x1b[0m"

fclean : clean
	cd libft && make fclean
	${RM} $(NAME)
	@echo "\x1b[31m \x1b[1m \n✅\tDelete [$(NAME)] \x1b[32mSuccess\n\x1b[0m"

re : fclean all