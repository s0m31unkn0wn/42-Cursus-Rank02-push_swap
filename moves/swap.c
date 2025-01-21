/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armirono <armirono@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 00:13:30 by armirono          #+#    #+#             */
/*   Updated: 2024/12/13 13:39:11 by armirono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_pushswap **stack)
{
	t_pushswap	*first;
	t_pushswap	*second;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	first->prev = second;
	second->prev = NULL;
	if (first->next)
		first->next->prev = first;
}

void	sa(t_pushswap **stack_a, bool print)
{
	swap(stack_a);
	if (!print)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_pushswap **stack_b, bool print)
{
	swap(stack_b);
	if (!print)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_pushswap **stack_a, t_pushswap **stack_b, bool print)
{
	swap(stack_a);
	swap(stack_b);
	if (!print)
		ft_putstr_fd("ss\n", 1);
}
