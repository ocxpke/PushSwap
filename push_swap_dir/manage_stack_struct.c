/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_stack_struct.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-ara < jose-ara@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:48:38 by jose-ara          #+#    #+#             */
/*   Updated: 2025/01/02 17:37:11 by jose-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*init_stacks(int argc, char **args)
{
	t_stacks	*ret;
	size_t		cont;

	ret = (t_stacks *)ft_calloc(1, sizeof(t_stacks));
	if (!ret)
		return (NULL);
	ret->size_a = count_all_words(argc, args);
	ret->size_b = 0;
	ret->stack_b = NULL;
	ret->stack_a = init_stack_a(argc, args, 1);
	if (!(ret->stack_a) || !check_stack_a(ret->stack_a, ret->size_a))
	{
		free(ret->stack_a);
		free(ret);
		write(2, "Error\n", 6);
		return (NULL);
	}
	cont = 0;
	return (ret);
}

void	free_stacks(t_stacks **stacks)
{
	free((*stacks)->stack_a);
	free((*stacks)->stack_b);
	free((*stacks));
	(*stacks) = NULL;
}

void	print_stacks(t_stacks *stacks)
{
	size_t	max;
	size_t	cont;

	max = stacks->size_a;
	if (max < stacks->size_b)
		max = stacks->size_b;
	printf("<------------>\n");
	cont = 0;
	while (cont < max)
	{
		if (cont < (stacks->size_a))
			printf("%d", stacks->stack_a[cont]);
		else
			printf(" ");
		printf(" ");
		if (cont < (stacks->size_b))
			printf("%d\n", stacks->stack_b[cont]);
		else
			printf(" \n");
		cont++;
	}
	printf("--------\na      b\n");
}
