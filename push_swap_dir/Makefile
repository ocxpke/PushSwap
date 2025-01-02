NAME = push_swap.a

NAME_EXEC = push_swap

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
	rm -f $(OBJ)

fclean: clean
	rm -f ../$(NAME_EXEC)
	rm -f $(NAME)

re: fclean $(NAME)

exec: $(OBJ)
	cc $(flags) push_swap.c $(OBJ) -o $(NAME_EXEC)
	mv $(NAME_EXEC) ../

.PHONY: all clean fclean re bonus exec
