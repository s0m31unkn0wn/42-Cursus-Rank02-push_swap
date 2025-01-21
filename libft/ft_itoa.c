/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armirono <armirono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 23:57:11 by armirono          #+#    #+#             */
/*   Updated: 2023/11/10 19:12:53 by armirono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_characters(int k)
{
	int	characters;

	characters = 0;
	if (k < 0)
	{
		k *= -1;
		characters++;
	}
	else if (k == 0)
		return (1);
	while (k)
	{
		k /= 10;
		characters++;
	}
	return (characters);
}

char	*ft_itoa(int n)
{
	char	*output;
	int		len;
	long	longn;

	len = count_characters(n);
	output = (char *)malloc((len + 1) * sizeof(char));
	if (!output)
		return (NULL);
	longn = (long)n;
	if (n < 0)
		longn *= -1;
	output[len] = 0;
	while (len--)
	{
		output[len] = longn % 10 + 48;
		longn /= 10;
	}
	if (n < 0)
		output[0] = 45;
	return (output);
}
