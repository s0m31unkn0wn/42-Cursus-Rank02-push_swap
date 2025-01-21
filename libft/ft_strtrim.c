/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armirono <armirono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:09:53 by armirono          #+#    #+#             */
/*   Updated: 2023/11/09 17:14:48 by armirono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	searchengine(char c, char const *set1)
{
	size_t	i;

	i = 0;
	while (set1[i])
	{
		if (set1[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (0);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (searchengine(s1[start], set) == 1)
		start++;
	while (searchengine(s1[end], set) == 1)
		end--;
	return (ft_substr(s1, start, end - start + 1));
}
