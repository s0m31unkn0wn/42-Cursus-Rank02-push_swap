/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armirono <armirono@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:12:05 by armirono          #+#    #+#             */
/*   Updated: 2024/12/13 13:11:10 by armirono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_pushswap **stack)
{
	t_pushswap	*tail;

	if (!*stack || !(*stack)->next)
		return ;
	tail = ft_lstlast(*stack);
	tail->prev->next = NULL;
	tail->next = *stack;
	tail->prev = NULL;
	*stack = tail;
	tail->next->prev = tail;
}

void	rra(t_pushswap **stack_a, bool print)
{
	reverse_rotate(stack_a);
	if (!print)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_pushswap **stack_b, bool print)
{
	reverse_rotate(stack_b);
	if (!print)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_pushswap **stack_a, t_pushswap **stack_b, bool print)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (!print)
		ft_putstr_fd("rrr\n", 1);
}
