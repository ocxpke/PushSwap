/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_reverse_r_func.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-ara < jose-ara@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:47:50 by jose-ara          #+#    #+#             */
/*   Updated: 2024/12/23 13:05:06 by jose-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate_list(int *list, int len)
{
	int	i;
	int	tmp;
	int	last;

	if (len <= 1)
		return ;
	i = 0;
	last = list[i];
	while (i < len - 1)
	{
		tmp = list[i + 1];
		list[i + 1] = last;
		last = tmp;
		i++;
	}
	list[0] = last;
}

void	rra(t_stacks *stacks, int out)
{
	if (out)
		write(1, "rra\n", 4);
	reverse_rotate_list(stacks->stack_a, stacks->size_a);
}

void	rrb(t_stacks *stacks, int out)
{
	if (out)
		write(1, "rrb\n", 4);
	reverse_rotate_list(stacks->stack_b, stacks->size_b);
}

void	rrr(t_stacks *stacks, int out)
{
	if (out)
		write(1, "rrr\n", 4);
	rra(stacks, 0);
	rrb(stacks, 0);
}
