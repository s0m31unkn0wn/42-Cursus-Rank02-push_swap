/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armirono <armirono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 00:48:55 by armirono          #+#    #+#             */
/*   Updated: 2023/11/06 00:54:47 by armirono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*modified_strcpy(char *dest1, const char *src1)
{
	int	k;

	k = 0;
	while (src1[k])
	{
		dest1[k] = src1[k];
		k++;
	}
	dest1[k] = 0;
	return (dest1);
}

char	*ft_strdup(const char *src)
{
	char	*dest;

	if (!src)
		return (0);
	dest = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!dest)
		return (0);
	modified_strcpy(dest, src);
	return (dest);
}
