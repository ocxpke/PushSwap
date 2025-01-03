NAME = push_swap.a

NAME_EXEC = push_swap

LIBFT_DIR = ./libft

LIBFT_LIB = ./libft/libft.a

Sources = ft_split_utils.c\
	ft_split.c\
	init_stack_a.c\
	manage_stack_struct.c\
	operations.c\
	optimizations.c\
	ordering.c\
	push_swap_push_func.c\
	push_swap_swap_func.c\
	push_swap_reverse_r_func.c\
	push_swap_rotate_func.c\
	push_swap_utils.c\
	stack_order.c

OBJ = $(Sources:.c=.o)

flags = -Wall -Wextra -Werror

all:$(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	cc -c $< -o $@ $(flags)

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f ../$(NAME_EXEC)
	rm -f $(NAME)

re: fclean $(NAME)

exec: $(OBJ)
	make -C $(LIBFT_DIR)
	cc $(flags) push_swap.c $(OBJ) $(LIBFT_LIB) -o $(NAME_EXEC)
	mv $(NAME_EXEC) ../

.PHONY: all clean fclean re bonus exec
