NAME = libftgnl.a
INCLUDE = ../include
LIBFT = ../libft
CC = cc
CFLAGS = -Wall -Werror -Wextra -I
RM = rm -f
AR = ar rcs

SRC_FILES = get_next_line

SRC = $(addsuffix .c, $(SRC_FILES))
OBJ = $(addsuffix .o, $(SRC_FILES))

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C $(LIBFT)
	@cp ${LIBFT}/libft.a .
	@mv libft.a $(NAME)
	$(AR) $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean :
	@$(RM) -rf $(OBJ)
	@make clean -C $(LIBFT)

fclean : clean
	@$(RM) -f $(NAME)
	@$(RM) -f $(LIBFT)/libft.a

re : fclean all

.PHONY : all clean fclean re