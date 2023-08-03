NAME = fdf
INCLUDE = include
LIBFT = libft
PRINTF = printf
GNL = get_next_line

clean:
	@make clean -C $(LIBFT)
	@make clean -C $(PRINTF)
	@make clean -C $(GNL)

fclean :clean
	@make fclean -C $(LIBFT)
	@make fclean -C $(PRINTF)
	@make fclean -C $(GNL)
	@rm -f $(NAME)
