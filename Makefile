LIBFT = ./libft/libft.a

NAME = cub3D

SRCS	= $(wildcard *.c) \
			$(wildcard start_game/*.c) \
			$(wildcard libft/*.c) \
			$(wildcard map_check/*.c) \
			$(wildcard draw/*.c) \
			$(wildcard game_drow/*.c)

CC = cc

.c.o:
	@${CC} ${WALL} -c $< -o ${<:.c=.o}

FLAGS = -Wall -Wextra -Werror
#  -lmlx -framework OpenGL -framework Appkit
# ML = -lft -lmlx -framework OpenGL -framework Appkit

ML = -lmlx -framework OpenGL -framework Appkit

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	@$(MAKE) -C ./libft
	@cp libft/libft.a $(NAME)
	@$(CC) $(FLAGS) $(ML) $(LIBFT) $(SRCS) -o $(NAME)
	@echo "you can ran cub3D"

all : $(NAME)

clean :
	@$(MAKE) clean -C ./libft
	@rm -rf $(OBJS)

fclean : clean
	@$(MAKE) fclean -C ./libft
	@rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re