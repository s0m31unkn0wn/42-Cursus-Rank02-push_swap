/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armirono <armirono@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:59:06 by armirono          #+#    #+#             */
/*   Updated: 2024/12/13 13:46:18 by armirono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	set_target_b(t_pushswap *stack_a, t_pushswap *stack_b)
{
	t_pushswap	*current_a;
	t_pushswap	*target_node;
	long		best_match_value;

	while (stack_b)
	{
		best_match_value = LONG_MAX;
		target_node = NULL;
		current_a = stack_a;
		while (current_a)
		{
			if ((current_a->value > stack_b->value)
				&& (current_a->value < best_match_value))
			{
				best_match_value = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_value == LONG_MAX)
			stack_b->target_node = find_min(stack_a);
		else
			stack_b->target_node = target_node;
		stack_b = stack_b->next;
	}
}

void	init_nodes_b(t_pushswap *stack_a, t_pushswap *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_b(stack_a, stack_b);
}
