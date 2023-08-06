NAME = fdf
INCLUDE = include

LIBFT = libft
PRINTF = printf
GNL = get_next_line
MINILIBX = mlx

SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE) -Imlx
all: $(NAME)

$(NAME):$(OBJS)
	@make -C ${LIBFT}
	@make -C $(PRINTF)
	@make -C $(GNL)
	@make -C $(MINILIBX)
	@cp ${MINILIBX}/libmlx.dylib .
	${CC} ${CFLAGS} -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS) ${PRINTF}/libftprintf.a ${GNL}/libftgnl.a

clean:
	@make clean -C ${LIBFT}
	@make clean -C $(PRINTF)
	@make clean -C $(GNL)
	@make clean -C $(MINILIBX)

fclean :clean
	@make fclean -C $(PRINTF)
	@make fclean -C $(GNL)
	@make fclean -C ${LIBFT}
	@make clean -C $(MINILIBX)
	@rm -f libmlx.dylib
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re