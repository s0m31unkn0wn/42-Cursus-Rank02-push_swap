/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armirono <armirono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 23:54:49 by armirono          #+#    #+#             */
/*   Updated: 2023/11/14 20:32:07 by armirono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	chr;

	if (!s)
		return (NULL);
	str = (unsigned char *)s;
	chr = (unsigned char)c;
	while (str && n--)
	{
		if (*str == chr)
			return ((void *)str);
		str++;
	}
	return (0);
}
