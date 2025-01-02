/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-ara < jose-ara@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:50:49 by jose-ara          #+#    #+#             */
/*   Updated: 2025/01/02 14:26:12 by jose-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Calculates the ocst of ordering that number
 *
 * @param stacks Pointer to the stacks
 * @param pos Position of the element
 * @return The total cost of ordering that number (+1 because of push operation)
 */
static int	order_elems(t_stacks *stacks, int pos)
{
	int		ret;
	int		mid;
	size_t	pos_b;

	ret = 0;
	mid = (stacks->size_a / 2);
	pos_b = where_to_pb(stacks, stacks->stack_a[pos], find_min(stacks->stack_b,
				stacks->size_b), find_max(stacks->stack_b, stacks->size_b));
	if (pos > mid)
		ret += ((stacks->size_a) - pos);
	else
		ret += pos;
	if (pos_b > (stacks->size_b / 2))
		ret += ((stacks->size_b) - pos_b);
	else
		ret += pos_b;
	optimize_costs(stacks, pos, pos_b, &ret);
	return (ret + 1);
}

/**
 * @brief Generates an array of integers with all the costs of each
 * element of stack A
 *
 * @param stacks Pointer to stacks
 * @return The array with all costs or NULL if somethi went wrong
 */
static int	*steps_to_order_stack(t_stacks *stacks)
{
	int		*ret;
	size_t	cont;

	ret = (int *)ft_calloc(1, stacks->size_a * sizeof(int));
	if (!ret)
		return (NULL);
	cont = 0;
	while (cont < stacks->size_a)
	{
		ret[cont] = order_elems(stacks, cont);
		cont++;
	}
	return (ret);
}

/**
 * @brief While stack A size > 3 selects the best option to send to b
 *
 * @param stacks Pointer to stacks
 * @return Void
 */
static void	general_ordering(t_stacks *stacks)
{
	int		*oper;
	int		min_opers;
	int		min_pos;
	size_t	i;

	while (stacks->size_a > 3)
	{
		oper = steps_to_order_stack(stacks);
		min_opers = oper[0];
		min_pos = 0;
		i = 0;
		while (i < stacks->size_a)
		{
			if (min_opers > oper[i])
			{
				min_opers = oper[i];
				min_pos = i;
			}
			i++;
		}
		exec_min(stacks, min_pos);
		free(oper);
	}
}

int	are_stacks_in_order(int *stack, int len, int mode)
{
	int	cont;
	int	ret;

	cont = 0;
	ret = 1;
	while ((cont < (len - 1)) && ret)
	{
		if (mode && (stack[cont] < stack[cont + 1]))
			ret = 0;
		else if (!mode && (stack[cont] > stack[cont + 1]))
			ret = 0;
		cont++;
	}
	return (ret);
}

void	main_order(t_stacks *stacks)
{
	if (are_stacks_in_order(stacks->stack_a, stacks->size_a, 0))
		return ;
	if (stacks->size_a <= 3)
	{
		order_bellow3(stacks);
		return ;
	}
	if (stacks->size_a > 4)
		pb(stacks, 1);
	pb(stacks, 1);
	if ((stacks->size_b > 1) && (stacks->stack_b[0] < stacks->stack_b[1])
		&& (stacks->stack_a[1] > stacks->stack_b[1]))
		ss(stacks, 1);
	else if ((stacks->size_b > 1) && (stacks->stack_b[0] < stacks->stack_b[1]))
		sb(stacks, 1);
	general_ordering(stacks);
	order3_elem(stacks);
	back_to_a(stacks);
	finalize_stack_a(stacks);
}
