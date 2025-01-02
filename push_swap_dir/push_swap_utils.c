/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-ara < jose-ara@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:52:42 by jose-ara          #+#    #+#             */
/*   Updated: 2025/01/02 18:17:07 by jose-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bzero(void *s, size_t n)
{
	char	*cpy;

	cpy = (char *)s;
	while (n)
	{
		(*cpy) = 0;
		cpy++;
		n--;
	}
}

void	*ft_calloc(size_t nmeb, size_t size)
{
	void				*ptr;
	void				*cpy_ptr;
	unsigned long int	to_cmp;

	to_cmp = (unsigned long int)nmeb * (unsigned long int)size;
	if (!to_cmp || (to_cmp >= INT_MAX))
		return (malloc(0));
	ptr = malloc(nmeb * size);
	if (!ptr)
		return (ptr);
	cpy_ptr = ptr;
	while (nmeb--)
	{
		ft_bzero(ptr, size);
		ptr += size;
	}
	return (cpy_ptr);
}

long long int	ft_atoi(const char *nptr)
{
	long long int	minus;
	long long int	number;

	number = 0;
	minus = 1;
	while (*nptr == ' ' || *nptr == '\n' || *nptr == '\t' || *nptr == '\r'
		|| *nptr == '\v' || *nptr == '\f')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			minus = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr) && *nptr)
	{
		number = (number * 10 + ((*nptr) - '0'));
		nptr++;
	}
	return (number * minus);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*cpy_dst;
	unsigned char	*cpy_src;

	cpy_dst = (unsigned char *)dst;
	cpy_src = (unsigned char *)src;
	if (!n || dst == src)
		return (dst);
	while (n)
	{
		*cpy_dst = *cpy_src;
		cpy_dst++;
		cpy_src++;
		n--;
	}
	return (dst);
}
