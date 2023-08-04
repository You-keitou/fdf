NAME = fdf
INCLUDE = include

LIBFT = libft
PRINTF = printf
GNL = get_next_line

SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INCLUDE)
all: $(NAME)

$(NAME):$(OBJS)
	@make -C ${LIBFT}
	@make -C $(PRINTF)
	@make -C $(GNL)
	${CC} ${CFLAGS} -o $(NAME) $(OBJS) ${PRINTF}/libftprintf.a ${GNL}/libftgnl.a

clean:
	@make clean -C ${LIBFT}
	@make clean -C $(PRINTF)
	@make clean -C $(GNL)

fclean :clean
	@make fclean -C $(PRINTF)
	@make fclean -C $(GNL)
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re