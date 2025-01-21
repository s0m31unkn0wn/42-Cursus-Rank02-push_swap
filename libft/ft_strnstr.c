/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armirono <armirono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 01:49:11 by armirono          #+#    #+#             */
/*   Updated: 2023/12/12 23:20:35 by armirono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* static int	ft_searchengine(const char *hay, const char *need,
				size_t len1, size_t i)
{
	size_t	j;

	j = 0;
	while (need[j] && hay[j])
	{
		if (need[j] != hay[j])
			return (0);
		i++;
		j++;
	}
	if (!hay[j] && need[j])
		return (0);
	if (i > len1)
		return (0);
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = -1;
	if (!haystack)
		return (0);
	if (!needle)
		return ((char *)haystack);
	if (needle[0] == '\0' && haystack[0] == '\0')
		return ((char *)haystack);
	while (haystack[++i] && (i < len))
	{
		if (haystack[i] == needle[0])
			if (ft_searchengine(&haystack[i], needle, len, i))
				return ((char *)&haystack[i]);
	}
	return (0);
} */

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!haystack || !needle)
		return (0);
	if (!needle[0])
		return ((char *)haystack);
	while (haystack[i] && (i < len))
	{
		if (haystack[i] == needle[0])
		{
			while (needle[j] && needle[j] == haystack[i + j] && (i + j < len))
			{
				if (!needle[j + 1])
					return ((char *)&haystack[i]);
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
