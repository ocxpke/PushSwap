/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-ara < jose-ara@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:56:22 by jose-ara          #+#    #+#             */
/*   Updated: 2025/01/05 11:45:03 by jose-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	digit_len(char *str)
{
	int	ret;

	ret = 0;
	if (*str == '-')
	{
		ret++;
		str++;
	}
	while (str[ret] && ft_isdigit(str[ret]))
		ret++;
	return (ret);
}

static void	add_splitted(int **ret, char **splitted, size_t *pos)
{
	int				cont_w;
	ssize_t			cont_l;
	long long int	val;

	cont_w = 0;
	while (splitted[cont_w])
	{
		cont_l = 0;
		while (cont_l < ft_strlen_ss(splitted[cont_w]))
		{
			val = ft_atoi_long_long(&splitted[cont_w][cont_l]);
			if (val > INT_MAX || val < INT_MIN
				|| digit_len(&splitted[cont_w][cont_l]) > 10)
			{
				free(*ret);
				*ret = 0;
				return ;
			}
			ret[0][*pos] = ft_atoi(&splitted[cont_w][cont_l]);
			cont_l += (digit_len(&splitted[cont_w][cont_l]) + 1);
		}
		(*pos)++;
		cont_w++;
	}
}

int	count_all_words(int argc, char **args)
{
	int	ret;
	int	iter;

	ret = 0;
	iter = 1;
	while (iter < argc)
	{
		ret += count_words(args[iter], ' ');
		iter++;
	}
	return (ret);
}

int	check_stack_a(int *stack, int len)
{
	int	ret;
	int	iter;
	int	cont;

	ret = 1;
	iter = 0;
	while (iter < len && ret)
	{
		cont = iter + 1;
		while (cont < len && stack[iter] != stack[cont])
			cont++;
		if (cont != len)
			ret = 0;
		iter++;
	}
	return (ret);
}

int	*init_stack_a(int argc, char **args, int cont)
{
	int		*ret;
	size_t	iter;
	char	**splitted;

	ret = (int *)ft_calloc(1, count_all_words(argc, args) * sizeof(int));
	if (!ret)
		return (NULL);
	iter = 0;
	while ((cont < argc) && ret)
	{
		splitted = ft_split(args[cont], ' ');
		if (!splitted || !check_splitted(splitted) || !ft_strlen_ss(args[cont]))
		{
			free(ret);
			free_back(splitted);
			return (NULL);
		}
		add_splitted(&ret, splitted, &iter);
		free_back(splitted);
		cont++;
	}
	return (ret);
}
