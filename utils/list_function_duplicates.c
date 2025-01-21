/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_function_duplicates.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armirono <armirono@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 20:23:52 by armirono          #+#    #+#             */
/*   Updated: 2024/12/13 14:56:50 by armirono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pushswap	*find_min(t_pushswap *stack)
{
	t_pushswap	*min_node;
	long		min;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	min_node = stack;
	while (stack)
	{
		if ((stack->value < min))
		{
			min = stack->value;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

int	ft_lstsize(t_pushswap *lst)
{
	int			i;
	t_pushswap	*head;

	if (!lst)
		return (0);
	i = 0;
	head = lst;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

t_pushswap	*ft_lstlast(t_pushswap *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

bool	is_sorted(t_pushswap *stack)
{
	if (!stack)
		return (true);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_pushswap	*find_max(t_pushswap *stack)
{
	t_pushswap	*max_node;
	long		max;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if ((stack->value > max))
		{
			max = stack->value;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}
