/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armirono <armirono@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:15:02 by armirono          #+#    #+#             */
/*   Updated: 2024/12/13 12:45:52 by armirono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_pushswap **stack_to, t_pushswap **stack_from)
{
	t_pushswap	*pushed_node;

	if (!*stack_from)
		return ;
	pushed_node = *stack_from;
	*stack_from = (*stack_from)->next;
	if (*stack_from)
		(*stack_from)->prev = NULL;
	pushed_node->prev = NULL;
	if (!*stack_to)
	{
		*stack_to = pushed_node;
		pushed_node->next = NULL;
	}
	else
	{
		pushed_node->next = *stack_to;
		pushed_node->next->prev = pushed_node;
		*stack_to = pushed_node;
	}
}

void	pa(t_pushswap **stack_a, t_pushswap **stack_b, bool print)
{
	push(stack_a, stack_b);
	if (!print)
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_pushswap **stack_b, t_pushswap **stack_a, bool print)
{
	push(stack_b, stack_a);
	if (!print)
		ft_putstr_fd("pb\n", 1);
}
