/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armirono <armirono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 23:51:18 by armirono          #+#    #+#             */
/*   Updated: 2023/11/18 19:18:05 by armirono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	long long	len;

	len = (long long) ft_strlen(s);
	if (!s)
		return (NULL);
	while (len >= 0)
	{
		if (s[len] == (char) c)
			return ((char *)&s[len]);
		len--;
	}
	return (NULL);
}
