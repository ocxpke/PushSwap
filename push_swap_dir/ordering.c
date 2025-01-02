/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordering.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-ara < jose-ara@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:54:18 by jose-ara          #+#    #+#             */
/*   Updated: 2024/12/29 19:04:26 by jose-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	find_min(int *stack, int len)
{
	size_t	pos;
	int		cont;
	int		min_num;

	cont = 0;
	pos = 0;
	min_num = stack[0];
	while (cont < len)
	{
		if (min_num > stack[cont])
		{
			pos = cont;
			min_num = stack[cont];
		}
		cont++;
	}
	return (pos);
}

size_t	find_max(int *stack, int len)
{
	size_t	pos;
	int		cont;
	int		max_num;

	cont = 0;
	pos = 0;
	max_num = stack[0];
	while (cont < len)
	{
		if (max_num < stack[cont])
		{
			pos = cont;
			max_num = stack[cont];
		}
		cont++;
	}
	return (pos);
}

void	order3_elem(t_stacks *stacks)
{
	int	pos_max;

	if (are_stacks_in_order(stacks->stack_a, stacks->size_a, 0))
		return ;
	pos_max = find_max(stacks->stack_a, stacks->size_a);
	if (pos_max == 0 && (stacks->stack_a[1] > stacks->stack_a[2]))
	{
		ra(stacks, 1);
		sa(stacks, 1);
	}
	else if (pos_max == 0)
		ra(stacks, 1);
	else if (pos_max == 1 && stacks->stack_a[0] < stacks->stack_a[2])
	{
		rra(stacks, 1);
		sa(stacks, 1);
	}
	else if (pos_max == 1)
		rra(stacks, 1);
	else if (pos_max == 2)
		sa(stacks, 1);
}

void	order_bellow3(t_stacks *stacks)
{
	if (stacks->size_a == 2 && (stacks->stack_a[0] > stacks->stack_a[1]))
		sa(stacks, 1);
	else if (stacks->size_a == 3)
		order3_elem(stacks);
}
