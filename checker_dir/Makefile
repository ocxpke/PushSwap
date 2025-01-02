NAME = checker

Sources = checker.c\
	get_next_line_utils.c\
	get_next_line.c

OBJ = $(Sources:.c=.o)

flags = -Wall -Wextra -Werror

PUSH_SWAP_PATH = ../push_swap_dir/

PUSH_SWAP_LIB = push_swap.a

all: $(NAME)

$(PUSH_SWAP_LIB):
	make -C $(PUSH_SWAP_PATH)
	cp $(PUSH_SWAP_PATH)$(PUSH_SWAP_LIB) .

$(NAME): $(OBJ) $(PUSH_SWAP_LIB)
	cc $(flags) $(OBJ) -L. -l:$(PUSH_SWAP_LIB) -o $(NAME)
	mv $(NAME) ../

%.o: %.c
	cc -c $< -o $@ $(flags)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../$(NAME)
	rm -f $(PUSH_SWAP_LIB)

re: fclean $(NAME)

.PHONY: all clean fclean re
