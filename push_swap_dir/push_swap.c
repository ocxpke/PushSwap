/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-ara < jose-ara@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:44:29 by jose-ara          #+#    #+#             */
/*   Updated: 2024/12/29 14:15:17 by jose-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **vargs)
{
	t_stacks	*stacks;

	if (argc <= 1)
		return (-1);
	stacks = init_stacks(argc, vargs);
	if (!stacks)
		return (-1);
	main_order(stacks);
	free_stacks(&stacks);
}
