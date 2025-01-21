/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armirono <armirono@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:29:16 by armirono          #+#    #+#             */
/*   Updated: 2024/12/13 19:04:49 by armirono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	count_words(char *s, char c)
{
	bool	inside_word;
	int		counter;

	inside_word = 0;
	counter = 0;
	while (*s)
	{
		if (*s == c)
		{
			inside_word = 0;
			s++;
			continue ;
		}
		if (!inside_word)
		{
			++counter;
			inside_word = 1;
		}
		s++;
	}
	return (counter);
}

static char	*get_next_word(char *s, char c)
{
	static int	cursor = 0;
	char		*next_word;
	int			i;
	int			len;

	len = 0;
	i = 0;
	while (s[cursor] && (s[cursor] == c))
		++cursor;
	while (s[cursor + len] && (s[cursor + len] != c))
		++len;
	next_word = malloc(sizeof(char) * (len + 1));
	if (!next_word)
		return (NULL);
	while (s[cursor] && (s[cursor] != c))
		next_word[i++] = s[cursor++];
	next_word[i] = '\0';
	return (next_word);
}

static char	**free_split(char **s, int i)
{
	while (i > -1)
		free(s[i--]);
	free(s);
	return (NULL);
}

char	**new_split(char *s, char c)
{
	int		wordcount;
	char	**result;
	int		i;

	i = 0;
	wordcount = count_words(s, c);
	if (!wordcount)
		exit(1);
	result = malloc(sizeof(char *) * (size_t)(wordcount + 2));
	if (!result)
		return (NULL);
	while (wordcount-- > 0)
	{
		result[i] = get_next_word(s, c);
		if (!result[i])
			return (free_split(result, i));
		i++;
	}
	result[i] = NULL;
	return (result);
}
