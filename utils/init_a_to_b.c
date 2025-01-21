/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armirono <armirono@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:38:30 by armirono          #+#    #+#             */
/*   Updated: 2024/12/13 13:45:44 by armirono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	current_index(t_pushswap *stack)
{
	int	median;
	int	i;

	i = 0;
	if (!stack)
		return ;
	median = ft_lstsize(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
		++i;
	}
}

static void	set_target_a(t_pushswap *stack_a, t_pushswap *stack_b)
{
	t_pushswap	*current_b;
	t_pushswap	*target_node;
	long		best_match_value;

	while (stack_a)
	{
		best_match_value = LONG_MIN;
		current_b = stack_b;
		target_node = NULL;
		while (current_b)
		{
			if ((current_b->value < stack_a->value)
				&& (current_b->value > best_match_value))
			{
				best_match_value = current_b->value;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (target_node == NULL)
			target_node = find_max(stack_b);
		stack_a->target_node = target_node;
		stack_a = stack_a->next;
	}
}

static void	cost_analysis_a(t_pushswap *stack_a, t_pushswap *stack_b)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(stack_a);
	size_b = ft_lstsize(stack_b);
	while (stack_a)
	{
		stack_a->push_cost = stack_a->index;
		if (!(stack_a->above_median))
			stack_a->push_cost = size_a - (stack_a->index);
		if (stack_a->target_node->above_median)
			stack_a->push_cost += stack_a->target_node->index;
		else
			stack_a->push_cost += size_b - (stack_a->target_node->index);
		stack_a = stack_a->next;
	}
}

void	set_cheapest(t_pushswap *stack)
{
	long		cheapest_value;
	t_pushswap	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = 1;
}

void	init_nodes_a(t_pushswap *stack_a, t_pushswap *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_a(stack_a, stack_b);
	cost_analysis_a(stack_a, stack_b);
	set_cheapest(stack_a);
}
