/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-ara < jose-ara@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:56:31 by jose-ara          #+#    #+#             */
/*   Updated: 2025/01/02 18:52:32 by jose-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (0);
	while (*s1 && *s2 && ((unsigned char)(*s1) == (unsigned char)(*s2))
		&& n > 1)
	{
		s1++;
		s2++;
		n--;
	}
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}

int	exec_operations(t_stacks *stacks, char *str)
{
	if (!ft_strncmp(str, "rra\n", ft_strlen(str)))
		rra(stacks, 0);
	else if (!ft_strncmp(str, "rrb\n", ft_strlen(str)))
		rrb(stacks, 0);
	else if (!ft_strncmp(str, "rrr\n", ft_strlen(str)))
		rrr(stacks, 0);
	else if (!ft_strncmp(str, "sa\n", ft_strlen(str)))
		sa(stacks, 0);
	else if (!ft_strncmp(str, "sb\n", ft_strlen(str)))
		sb(stacks, 0);
	else if (!ft_strncmp(str, "ss\n", ft_strlen(str)))
		ss(stacks, 0);
	else if (!ft_strncmp(str, "pa\n", ft_strlen(str)))
		pa(stacks, 0);
	else if (!ft_strncmp(str, "pb\n", ft_strlen(str)))
		pb(stacks, 0);
	else if (!ft_strncmp(str, "ra\n", ft_strlen(str)))
		ra(stacks, 0);
	else if (!ft_strncmp(str, "rb\n", ft_strlen(str)))
		rb(stacks, 0);
	else if (!ft_strncmp(str, "rr\n", ft_strlen(str)))
		rr(stacks, 0);
	else
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	char		*str;
	t_stacks	*stacks;

	if (argc <= 1)
		return (-1);
	stacks = init_stacks(argc, argv);
	if (!stacks)
		return (-1);
	str = "a";
	while (str)
	{
		str = get_next_line(0);
		if (str && !exec_operations(stacks, str))
		{
			write(2, "Error\n", 6);
			return (-1);
		}
		free(str);
	}
	if (are_stacks_in_order(stacks->stack_a, stacks->size_a, 0)
		&& stacks->size_a >= 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stacks(&stacks);
}
