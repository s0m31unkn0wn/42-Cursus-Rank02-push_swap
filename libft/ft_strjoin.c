/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armirono <armirono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 23:50:55 by armirono          #+#    #+#             */
/*   Updated: 2024/10/17 21:20:10 by armirono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcat(char *dest, char *src)
{
	int	n;
	int	destlen;

	n = 0;
	destlen = ft_strlen(dest);
	while (src[n])
		dest[destlen++] = src[n++];
	dest[destlen] = 0;
	return (dest);
}

static int	total_length(char const *first, char const *second)
{
	int	total;

	total = ft_strlen(first) + ft_strlen(second) + 1;
	return (total);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;

	if (!s1 || !s2)
		return (0);
	joined = ft_calloc(total_length(s1, s2), sizeof(char));
	if (!joined)
		return (NULL);
	ft_strcat(joined, (char *)s1);
	ft_strcat(joined, (char *)s2);
	return (joined);
}
