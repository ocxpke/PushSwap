/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-ara < jose-ara@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:42:34 by jose-ara          #+#    #+#             */
/*   Updated: 2025/01/02 18:17:00 by jose-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stacks
{
	int			*stack_a;
	int			*stack_b;
	size_t		size_a;
	size_t		size_b;
}				t_stacks;

/**
 * PUSH_SWAP_UTILS.C
 */
/**
 * @brief Set first n-positions to 0
 *
 * @param s void pointer
 * @param n numer of bytes to check
 * @return void
 */
void			ft_bzero(void *s, size_t n);
/**
 * @brief Allocates nmeb * size bytes of memory and set them all to 0
 *
 * @param nmeb number of memory blocks
 * @param size size fo each block (in bytes)
 * @return pointer to the memory allocated or null
 */
void			*ft_calloc(size_t nmeb, size_t size);
/**
 * @brief Writes the first n-posstions of src into dst
 *
 * @param dst pointer of destination
 * @param src pointer of source
 * @param n the number of bytes to read
 * @return pointer to dst or null
 */
void			*ft_memcpy(void *dst, const void *src, size_t n);
/**
 * @brief Transformrs the ascii recived to long long integer
 *
 * @param nptr pointer to the string where the number is
 * @return the long long integer value
 */
long long int	ft_atoi(const char *nptr);

/**
 * MANAGE_STACK_STRUCT.C
 */
/**
 * @brief Initialise all stack components with the given input
 *
 * @param argc The number of total arguments
 * @param args All arguments passed
 * @return A pointer to the new stacks initialised
 */
t_stacks		*init_stacks(int argc, char **args);
/**
 * @brief Frees the memory used by the stack
 *
 * @param stacks A pointer to the memory location of the stack
 * @return void
 */
void			free_stacks(t_stacks **stacks);
/**
 * @brief Prints the stack information
 * @note Only used for debugging
 *
 * @param stacks Pointer to the stack
 * @return void
 */
void			print_stacks(t_stacks *stacks);

/**
 * PUSH_SWAP_SWAP_FUNC.C
 */
/**
 * @brief Swaps the first 2 elements of stack A
 *
 * @param stacks Pointer to stack
 * @param out Flag used for the output of the method
 * @return void
 */
void			sa(t_stacks *stacks, int out);
/**
 * @brief Swaps the first 2 elements of stack B
 *
 * @param stacks Pointer to stack
 * @param out Flag used for the output of the method
 * @return void
 */
void			sb(t_stacks *stacks, int out);
/**
 * @brief Swaps the first 2 elements of both stacks
 *
 * @param stacks Pointer to stack
 * @param out Flag used for the output of the method
 * @return void
 */
void			ss(t_stacks *stacks, int out);

/**
 * PUSH_SWAP_PUSH_FUNC.C
 */
/**
 * @brief Push the first elem of B to A
 *
 * @param stacks Pointer to stack
 * @param out Flag used for the output of the method
 * @return void
 */
void			pa(t_stacks *stacks, int out);
/**
 * @brief Push the first elem of A to B
 *
 * @param stacks Pointer to stack
 * @param out Flag used for the output of the method
 * @return void
 */
void			pb(t_stacks *stacks, int out);

/**
 * PUSH_SWAP_ROTATE_FUNC.C
 */
/**
 * @brief Rotates all stack A, moving the first element to the last position
 *
 * @param stacks Pointer to stack
 * @param out Flag used for the output of the method
 * @return void
 */
void			ra(t_stacks *stack, int out);
/**
 * @brief Rotates all stack B, moving the first element to the last position
 *
 * @param stacks Pointer to stack
 * @param out Flag used for the output of the method
 * @return void
 */
void			rb(t_stacks *stacks, int out);
/**
 * @brief Rotates both stacks, moving the first element to the last position
 *
 * @param stacks Pointer to stack
 * @param out Flag used for the output of the method
 * @return void
 */
void			rr(t_stacks *stacks, int out);

/**
 * PUSH_SWAP_REVERSE_ROTATE.C
 */
/**
 * @brief Reverse rotate all stack A,
	moving the last element to the first position
 *
 * @param stacks Pointer to stack
 * @param out Flag used for the output of the method
 * @return void
 */
void			rra(t_stacks *stack, int out);
/**
 * @brief Reverse rotate all stack B,
	moving the last element to the first position
 *
 * @param stacks Pointer to stack
 * @param out Flag used for the output of the method
 * @return void
 */
void			rrb(t_stacks *stacks, int out);
/**
 * @brief Reverse rotateboth stacks,
	moving the last element to the first position
 *
 * @param stacks Pointer to stack
 * @param out Flag used for the output of the method
 * @return void
 */
void			rrr(t_stacks *stacks, int out);

/**
 * FT_SPLIT.C
 */
/**
 * @brief Counts the total amount of numbers that have been passed
 *
 * @param s String to look in
 * @param c Separator normaly ' '
 * @return The numer of elements
 */
size_t			count_words(char const *s, char c);
/**
 * @brief Splits the string s in x-words eliminating the c char
 *
 * @param s string to split
 * @param c value to delete
 * @return pointer to positon of the first word or null
 */
char			**ft_split(char const *s, char c);
/**
 * @brief Frees all the splitted structure
 *
 * @param words Various strings, the splitted structure
 * @return Always NULL
 */
char			**free_back(char **words);

/**
 * FT_SPLIT_UTILS.C
 */
/**
 * @brief Returns if c is a numeric digit character or not
 *
 * @param c the ascii value of the character
 * @return if it is a numeric digit character or not
 */
int				ft_isdigit(int c);
/**
 * @brief Using ft_isdigit checks if all string elements are digit
 *
 * @param str String to be checked
 * @return 1 if it's everything ok, 0 if something went wrong
 */
int				ft_is_all_digit(const char *str);
/**
 * @brief Checks every component of the splitted structure,
	using ft_is_all_digit
 *
 * @param splitted The splitted structure
 * @return 1 if it's everything ok, 0 if something went wrong
 */
int				check_splitted(char **splitted);
/**
 * @brief Tries to take a substr from s
 *
 * @param s string we will make a substr from
 * @param start postion of the first character
 * @param len length of the substr
 * @return pointer to positon of substr or null
 */
char			*ft_substr(const char *s, unsigned int start, size_t len);
/**
 * @brief Gives you the length of s
 *
 * @param s string we will measure
 * @return size of s
 */
ssize_t			ft_strlen(const char *s);

/**
 * INIT_STACK_A.C
 */
/**
 * @brief Initialise th pointer of integers of the first stack
 *
 * @param argc Total number of arguments
 * @param args All parameters passed
 * @param cont Where to start reading from args
 * @return The pointer to the new stack or NULL if something went wrong
 */
int				*init_stack_a(int argc, char **args, int cont);
/**
 * @brief Counts the total amount of numbers passed through parameters
 *
 * @param argc Total number of arguments
 * @param args All parameters passed
 * @return The total amount of integers
 */
int				count_all_words(int argc, char **args);
/**
 * @brief Checks if all stack A is well initialise
 *
 * @param stack Pointer of integers to be checked
 * @param len Number of elements of the pointer
 * @return 1 if it's everything ok, 0 if something went wrong
 */
int				check_stack_a(int *stack, int len);

/**
 * STACK_ORDER.C
 */
/**
 * @brief Method used as a guide for ordering the stacks
 *
 * @param stacks Pointer to stacks
 * @return Void
 */
void			main_order(t_stacks *stacks);
/**
 * @brief Checks if the stack pass by paramter is ordered
 *
 * @param stack Pointer of integer to be checked
 * @param len Total amount of numbers in stack
 * @param mode 0 for ascending order, 1 descending order
 * @return 1 if it's everything ok, 0 if something went wrong
 */
int				are_stacks_in_order(int *stack, int len, int mode);

/**
 * ORDERING.C
 */
/**
 * @brief Manage ordering for 2 or 3 elements
 *
 * @param stacks Pointer to stacks
 * @return Void
 */
void			order_bellow3(t_stacks *stacks);
/**
 * @brief Orders the stack A with 3 elements
 *
 * @param stacks Pointer to stacks
 * @return Void
 */
void			order3_elem(t_stacks *stacks);
/**
 * @brief Finds the position of the highest element
 *
 * @param stack Stack with all elements
 * @param len The length of the stack
 * @return The position of the highest element
 */
size_t			find_max(int *stack, int len);
/**
 * @brief Finds the position of the lowest element
 *
 * @param stack Stack with all elements
 * @param len The length of the stack
 * @return The position of the lowest element
 */
size_t			find_min(int *stack, int len);

/**
 * OPERATIONS.C
 */
/**
 * @brief Executes the min operation found
 *
 * @param stacks Pointer of stacks
 * @param min The position of the min element
 * @return Void
 */
void			exec_min(t_stacks *stacks, int min);
/**
 * @brief Managemnet of the operations to roll back all elements to A
 *
 * @param stacks Pointer of stacks
 * @return Void
 */
void			back_to_a(t_stacks *stacks);
/**
 * @brief Calculates the number of operation to insert to stack B
 *
 * @param stacks Pointer of the stacks
 * @param act The actual new element
 * @param min_b The position of the lowest elem of stack B
 * @param max_b The position of the highest elem of stack B
 * @return The number of operations previous to make pb
 */
int				where_to_pb(t_stacks *stacks, int act, int min_b, int max_b);

/**
 * OPTIMIZATONS.C
 */
/**
 * @brief Executes the possible combinated moves
 *
 * @param stacks Pointer of the stacks
 * @param min The position of the lowest elem of stack
 * @param moves A pointer to the actual necesary moves
 * @param i The actual total moves needed on stack B
 * @return Void
 */
void			exec_comb_moves(t_stacks *stacks, size_t min, size_t *moves,
					size_t i);
/**
 * @brief Sets stack A first element to the lowest one setting,
 * all right the stack
 *
 * @param stacks Pointer of the stacks
 * @return Void
 */
void			finalize_stack_a(t_stacks *stacks);
/**
 * @brief Reduces the total quantity of moves needed when it's possible
 *
 * @param stacks Pointer of the stacks
 * @param pos Position of the stack A to be moved
 * @param pos_b Position of the stack B to be moved
 * @param ret The actual total moves needed
 * @return Void
 */
void			optimize_costs(t_stacks *stacks, size_t pos, size_t pos_b,
					int *ret);
#endif
