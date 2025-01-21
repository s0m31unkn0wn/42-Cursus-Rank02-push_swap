/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armirono <armirono@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:33:56 by armirono          #+#    #+#             */
/*   Updated: 2024/12/13 19:04:31 by armirono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	result;

	if (!str)
		return (0);
	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	if ((str[i] == 43) || (str[i] == 45))
	{
		if (str[i] == 45)
			sign *= -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (sign * result);
}

static void	lstnew_pushswap(t_pushswap **stack, int n)
{
	t_pushswap	*new_node;
	t_pushswap	*last_node;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_pushswap));
	if (!new_node)
	{
		free_stack(stack);
		error_msg("Error: Mallocing new node in lstnew_ps failed");
	}
	ft_memset(new_node, 0, sizeof(t_pushswap));
	new_node->value = n;
	if (!(*stack))
		*stack = new_node;
	else
	{
		last_node = ft_lstlast(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

void	init_stack_a(t_pushswap **stack_a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (ft_isnumber(argv[i]) == 0)
		{
			free_stack(stack_a);
			error_msg("Error: Argument not a number");
		}
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
		{
			free_stack(stack_a);
			error_msg("Error: Argument out of int bounds");
		}
		if (find_duplicates(*stack_a, (int)n))
		{
			free_stack(stack_a);
			error_msg("Error: Duplicate arguments");
		}
		lstnew_pushswap(stack_a, (int)n);
		i++;
	}
}

t_pushswap	*get_cheapest(t_pushswap *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	prep_for_push(t_pushswap **stack, t_pushswap *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, 0);
			else
				rra(stack, 0);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, 0);
			else
				rrb(stack, 0);
		}
	}
}
