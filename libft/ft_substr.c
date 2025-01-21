/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armirono <armirono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 22:23:13 by armirono          #+#    #+#             */
/*   Updated: 2023/11/21 00:21:59 by armirono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		start = ft_strlen(s);
	if ((ft_strlen(s) - start) <= len)
		len = ft_strlen(s) - start;
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while ((i < len) && s[start + i])
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = 0;
	return (result);
}
