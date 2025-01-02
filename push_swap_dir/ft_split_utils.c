/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-ara < jose-ara@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:53:24 by jose-ara          #+#    #+#             */
/*   Updated: 2025/01/02 13:18:33 by jose-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_is_all_digit(const char *str)
{
	int	ret;

	ret = 1;
	while (*str && ret)
	{
		if (ft_strlen(str) > 1 && (*str) == '-' && str[1] == '-')
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

ssize_t	ft_strlen(const char *s)
{
	ssize_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	cont;
	size_t	len_s;
	char	*substr;

	cont = 0;
	len_s = ft_strlen(s);
	if (len > len_s)
		len = len_s;
	if (start > len_s)
		len = 0;
	if (len > (len_s - start))
		len = len_s - start;
	substr = (char *)ft_calloc(1, len + 1);
	if (!substr)
		return (NULL);
	if (!(*s) || start > len_s)
		return (substr);
	while (cont < len && s[start + cont])
	{
		substr[cont] = s[start + cont];
		cont++;
	}
	substr[cont] = 0;
	return (substr);
}
