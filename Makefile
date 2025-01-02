CHECKER_PATH = ./checker_dir

PUSH_SWAP_PATH = ./push_swap_dir

all:
	make exec -C $(PUSH_SWAP_PATH)

bonus:
	make -C $(CHECKER_PATH)

clean:
	make clean -C $(CHECKER_PATH)
	make clean -C $(PUSH_SWAP_PATH)

fclean:
	make fclean -C $(CHECKER_PATH)
	make fclean -C $(PUSH_SWAP_PATH)

re: fclean all

.PHONY: all re fclean clean bonus
