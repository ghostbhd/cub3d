SRCS =	main.c parssing/src/*.c raycasting/*.c

CC = @cc

CFLAGS = -Wall -Wextra -Werror

RM = @rm -rf

AR = @ar -rc

NAME = cub3D

LIB = parssing/libft/libft.a

sanitize = -fsanitize=address -g && echo "\x1b[36m \n\t-fsanitize=address:\x1b[32m Used 💥\n"

all : $(NAME)

$(NAME) : ${SRCS}
	cd parssing/libft && make
	${CC} -pthread ${CFLAGS} $(SRCS) $(LIB) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "\x1b[32m \x1b[1m \n✅\tMandatory Compiled Successfully\n\t\x1b[0mProgram named -\x1b[33m ($(NAME))\n\x1b[0m"

clean :
	cd parssing/libft && make clean

fclean : clean
	cd parssing/libft && make fclean
	${RM} $(NAME)
	@echo "\x1b[31m \x1b[1m \n✅\tDelete [$(NAME)] \x1b[32mSuccess\n\x1b[0m"

re : fclean all

run : re
	make clean
	./$(NAME) maps/map.cub
	make fclean