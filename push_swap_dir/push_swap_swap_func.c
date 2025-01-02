/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_swap_func.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-ara < jose-ara@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 23:11:45 by jose-ara          #+#    #+#             */
/*   Updated: 2024/12/23 13:09:32 by jose-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sa(t_stacks *stacks, int out)
{
	if ((stacks->size_a) <= 1)
		return ;
	if (out)
		write(1, "sa\n", 3);
	swap(&stacks->stack_a[0], &stacks->stack_a[1]);
}

void	sb(t_stacks *stacks, int out)
{
	if ((stacks->size_b) <= 1)
		return ;
	if (out)
		write(1, "sb\n", 3);
	swap(&stacks->stack_b[0], &stacks->stack_b[1]);
}

void	ss(t_stacks *stacks, int out)
{
	if (out)
		write(1, "ss\n", 3);
	sa(stacks, 0);
	sb(stacks, 0);
}
