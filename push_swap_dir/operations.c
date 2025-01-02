/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-ara < jose-ara@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:14:16 by jose-ara          #+#    #+#             */
/*   Updated: 2024/12/29 19:15:39 by jose-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Rotates stack A and stack B for pushing
 *
 * @param stacks Pointer of the stacks
 * @param min The position of the lowest elem of stack A
 * @param min_b The position of the lowest elem of stack B
 * @param max_b The position of the highest elem of stack B
 * @return Void
 */
static void	rotate_stacks_pb(t_stacks *stacks, size_t min, int min_b, int max_b)
{
	int		act;
	size_t	i;
	size_t	moves;

	act = stacks->stack_a[min];
	i = where_to_pb(stacks, act, min_b, max_b);
	moves = i;
	if (moves > (stacks->size_b / 2))
		moves = stacks->size_b - moves;
	exec_comb_moves(stacks, min, &moves, i);
	while (stacks->stack_a[0] != act)
	{
		if (min > (stacks->size_a / 2))
			rra(stacks, 1);
		else
			ra(stacks, 1);
	}
	while (moves > 0)
	{
		if (i > stacks->size_b / 2)
			rrb(stacks, 1);
		else
			rb(stacks, 1);
		moves--;
	}
}

/**
 * @brief Calculates the rotation of stack A
 *
 * @param stacks Pointer of the stacks
 * @param min The new element to be inserted to stack A
 * @param min The position of the lowest elem of stack A
 * @param max The position of the highest elem of stack A
 * @return The number of rotation of stack A
 */
static int	rotate_a(t_stacks *stacks, int new, int min, int max)
{
	size_t	i;

	i = 0;
	while (i < stacks->size_a)
	{
		if ((stacks->stack_a[i] == max) && (new > max))
			return (i + 1);
		if ((stacks->stack_a[i] == min) && (new < min))
			return (i);
		if (((i + 1) < stacks->size_a) && (stacks->stack_a[i] < new)
			&& (stacks->stack_a[i + 1] > new))
			return (i + 1);
		i++;
	}
	return (0);
}

int	where_to_pb(t_stacks *stacks, int act, int min_b, int max_b)
{
	size_t	i;

	i = 0;
	while ((i < stacks->size_b))
	{
		if ((stacks->stack_b[i] == stacks->stack_b[max_b])
			&& ((act > stacks->stack_b[max_b]) || act < stacks->stack_b[min_b]))
			return (i);
		if (((i + 1) < stacks->size_b) && (stacks->stack_b[i] > act)
			&& (stacks->stack_b[i + 1] < act))
			return (i + 1);
		i++;
	}
	return (i);
}

void	exec_min(t_stacks *stacks, int min)
{
	int	min_b;
	int	max_b;

	max_b = find_max(stacks->stack_b, stacks->size_b);
	min_b = find_min(stacks->stack_b, stacks->size_b);
	rotate_stacks_pb(stacks, min, min_b, max_b);
	pb(stacks, 1);
}

void	back_to_a(t_stacks *stacks)
{
	int		max;
	int		min;
	int		moves;
	size_t	rt_a;

	while (stacks->size_b)
	{
		min = stacks->stack_a[find_min(stacks->stack_a, stacks->size_a)];
		max = stacks->stack_a[find_max(stacks->stack_a, stacks->size_a)];
		rt_a = rotate_a(stacks, stacks->stack_b[0], min, max);
		moves = rt_a;
		if (rt_a > stacks->size_a / 2)
			moves = stacks->size_a - rt_a;
		while (moves > 0)
		{
			if (rt_a > stacks->size_a / 2)
				rra(stacks, 1);
			else
				ra(stacks, 1);
			moves--;
		}
		pa(stacks, 1);
	}
}
