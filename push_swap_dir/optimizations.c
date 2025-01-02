/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-ara < jose-ara@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:44:20 by jose-ara          #+#    #+#             */
/*   Updated: 2024/12/29 18:57:06 by jose-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_comb_moves(t_stacks *stacks, size_t min, size_t *moves, size_t i)
{
	int	act;

	act = stacks->stack_a[min];
	if (!(((min > stacks->size_a / 2) && (i > stacks->size_b / 2))
			|| (((min <= stacks->size_a / 2) && (i <= stacks->size_b / 2)))))
		return ;
	while ((stacks->stack_a[0] != act) && ((*moves) > 0))
	{
		if ((min > stacks->size_a / 2) && (i > stacks->size_b / 2))
			rrr(stacks, 1);
		else
			rr(stacks, 1);
		(*moves)--;
	}
}

void	finalize_stack_a(t_stacks *stacks)
{
	size_t	min;

	min = find_min(stacks->stack_a, stacks->size_a);
	while (min > 0)
	{
		if (min > stacks->size_a / 2)
		{
			rra(stacks, 1);
			min = find_min(stacks->stack_a, stacks->size_a);
		}
		else
		{
			ra(stacks, 1);
			min = find_min(stacks->stack_a, stacks->size_a);
		}
	}
}

void	optimize_costs(t_stacks *stacks, size_t pos, size_t pos_b, int *ret)
{
	if ((pos > (stacks->size_a / 2)) && (pos_b > (stacks->size_b / 2)))
	{
		pos = (stacks->size_a - pos);
		pos_b = (stacks->size_b - pos_b);
		if (pos_b > pos)
			(*ret) = pos_b;
		else
			(*ret) = pos;
	}
	else if ((pos <= (stacks->size_a / 2)) && (pos_b <= (stacks->size_b / 2)))
	{
		if (pos_b > pos)
			(*ret) = pos_b;
		else
			(*ret) = pos;
	}
}
