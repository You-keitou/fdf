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
	@cp ${LIBFT}/libft.a .
	@mv libft.a $(NAME)
	$(AR) $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean :
	@$(RM) -rf $(OBJ)

fclean : clean
	@$(RM) -f $(NAME)

re : fclean all

.PHONY : all clean fclean re