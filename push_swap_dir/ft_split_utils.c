/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-ara < jose-ara@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:53:24 by jose-ara          #+#    #+#             */
/*   Updated: 2025/01/03 14:24:04 by jose-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_all_digit(const char *str)
{
	int	ret;

	ret = 1;
	while (*str && ret)
	{
		if (ft_strlen_ss(str) > 1 && (*str) == '-' && str[1] == '-')
			ret = 0;
		else if (!ft_isdigit(*str) && *str != '-')
			ret = 0;
		str++;
	}
	return (ret);
}

int	check_splitted(char **splitted)
{
	int	cont_w;

	cont_w = 0;
	while (splitted[cont_w])
	{
		if (!ft_is_all_digit(splitted[cont_w]))
			return (0);
		cont_w++;
	}
	return (1);
}

ssize_t	ft_strlen_ss(const char *s)
{
	ssize_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
