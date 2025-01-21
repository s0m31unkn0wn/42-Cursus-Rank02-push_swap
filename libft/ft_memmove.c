/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armirono <armirono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:19:42 by armirono          #+#    #+#             */
/*   Updated: 2023/11/12 23:34:30 by armirono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*char_dst;
	const unsigned char	*char_src;

	char_dst = dst;
	char_src = src;
	if (!dst || !src)
		return (dst);
	if ((char_src < char_dst) && (char_src < char_dst + len))
	{
		char_dst += len;
		char_src += len;
		while (len--)
			*--char_dst = *--char_src;
		return (dst);
	}
	else
		return (ft_memcpy(dst, src, len));
}
