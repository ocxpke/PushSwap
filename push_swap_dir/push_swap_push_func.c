/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_push_func.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-ara < jose-ara@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 23:21:20 by jose-ara          #+#    #+#             */
/*   Updated: 2024/12/23 13:06:12 by jose-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	copy_array(int *dest, int *src, int start, int end)
{
	int	cont;

	if (!start)
		cont = 1;
	else
		cont = 0;
	while (cont < end)
	{
		dest[start] = src[cont];
		start++;
		cont++;
	}
}

void	pa(t_stacks *stacks, int out)
{
	int	*new_a;
	int	*new_b;

	if (!stacks->size_b)
		return ;
	new_a = (int *)ft_calloc(1, (stacks->size_a + 1) * sizeof(int));
	if (!new_a)
		return ;
	new_b = (int *)ft_calloc(1, (stacks->size_b - 1) * sizeof(int));
	if (!new_b || !(stacks->size_b - 1))
	{
		free(new_b);
		new_b = NULL;
	}
	new_a[0] = stacks->stack_b[0];
	copy_array(new_a, stacks->stack_a, 1, stacks->size_a);
	copy_array(new_b, stacks->stack_b, 0, stacks->size_b);
	stacks->size_a += 1;
	stacks->size_b -= 1;
	free(stacks->stack_a);
	free(stacks->stack_b);
	stacks->stack_a = new_a;
	stacks->stack_b = new_b;
	if (out)
		write(1, "pa\n", 3);
}

void	pb(t_stacks *stacks, int out)
{
	int	*new_a;
	int	*new_b;

	if (!stacks->size_a)
		return ;
	new_a = (int *)ft_calloc(1, (stacks->size_a - 1) * sizeof(int));
	if (!new_a || !(stacks->size_a - 1))
	{
		free(new_a);
		new_a = NULL;
	}
	new_b = (int *)ft_calloc(1, (stacks->size_b + 1) * sizeof(int));
	if (!new_b)
		return ;
	new_b[0] = stacks->stack_a[0];
	copy_array(new_b, stacks->stack_b, 1, stacks->size_b);
	copy_array(new_a, stacks->stack_a, 0, stacks->size_a);
	stacks->size_a -= 1;
	stacks->size_b += 1;
	free(stacks->stack_a);
	free(stacks->stack_b);
	stacks->stack_a = new_a;
	stacks->stack_b = new_b;
	if (out)
		write(1, "pb\n", 3);
}
