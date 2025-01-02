/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotate_func.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-ara < jose-ara@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:16:04 by jose-ara          #+#    #+#             */
/*   Updated: 2024/12/23 13:07:57 by jose-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_list(int *list, int len)
{
	int	i;
	int	tmp;
	int	last;

	if (len <= 1)
		return ;
	i = len - 1;
	last = list[i];
	while (i > 0)
	{
		tmp = list[i - 1];
		list[i - 1] = last;
		last = tmp;
		i--;
	}
	list[len - 1] = last;
}

void	ra(t_stacks *stacks, int out)
{
	if (out)
		write(1, "ra\n", 3);
	rotate_list(stacks->stack_a, stacks->size_a);
}

void	rb(t_stacks *stacks, int out)
{
	if (out)
		write(1, "rb\n", 3);
	rotate_list(stacks->stack_b, stacks->size_b);
}

void	rr(t_stacks *stacks, int out)
{
	if (out)
		write(1, "rr\n", 3);
	ra(stacks, 0);
	rb(stacks, 0);
}
