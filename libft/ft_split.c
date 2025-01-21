/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armirono <armirono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:26:36 by armirono          #+#    #+#             */
/*   Updated: 2023/12/14 18:43:58 by armirono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sepa(char s2, char c2)
{
	if (!s2 || (s2 == c2))
		return (1);
	return (0);
}

static size_t	count_words(char const *s1, char c1)
{
	size_t	i;
	size_t	counter;

	i = 0;
	counter = 0;
	while (s1 && s1[i])
	{
		if ((sepa(s1[i], c1) == 0) && (sepa(s1[i + 1], c1) == 1))
			counter++;
		i++;
	}
	return (counter);
}

char	**free_er(char **result1, size_t *i)
{
	while (i[2] < i[3])
		free(result1[i[2]++]);
	free(result1);
	return (NULL);
}

static char	**mainloop(const char *src, char se, size_t *i)
{
	char	**result;

	result = malloc((i[2] + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	result[i[2]] = 0;
	while (i[1]--)
	{
		if (i[1] && (sepa(src[i[1]], se) == 1) && !(sepa(src[i[1] - 1], se)))
		{
			i[0] = i[1]--;
			while (i[1] && !(sepa(src[i[1]], se)) && !(sepa(src[i[1] - 1], se)))
				i[1]--;
			while (sepa(src[i[1]], se) == 1)
				i[1]++;
			i[2]--;
			result[i[2]] = ft_substr(src, i[1], (i[0] - i[1]));
			if (!result[i[2]])
				return (free_er(result, i));
			i[1] = i[0];
		}
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	size_t	i[4];
	char	**res;

	i[0] = 0;
	if (!s)
		return (NULL);
	i[1] = ft_strlen(s) + 1;
	i[2] = count_words(s, c);
	i[3] = count_words(s, c);
	res = mainloop(s, c, i);
	return (res);
}
// #include <stdio.h>

// int main () {
// 	char **s = ft_split("s", ' ');
// 	printf("%p   %p\n", s, s[0]);
// 	printf("%s\n", s[0]);
// }