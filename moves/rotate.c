/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armirono <armirono@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:16:52 by armirono          #+#    #+#             */
/*   Updated: 2024/12/13 13:13:41 by armirono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_pushswap **stack)
{
	t_pushswap	*tail;

	if (!*stack || !(*stack)->next)
		return ;
	tail = ft_lstlast(*stack);
	tail->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	tail->next->prev = tail;
	tail->next->next = NULL;
}

void	ra(t_pushswap **stack_a, bool print)
{
	rotate(stack_a);
	if (!print)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_pushswap **stack_b, bool print)
{
	rotate(stack_b);
	if (!print)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_pushswap **stack_a, t_pushswap **stack_b, bool print)
{
	rotate(stack_a);
	rotate(stack_b);
	if (!print)
		ft_putstr_fd("rr\n", 1);
}
