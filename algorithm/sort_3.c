/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armirono <armirono@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 00:13:20 by armirono          #+#    #+#             */
/*   Updated: 2024/12/13 12:12:36 by armirono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_pushswap **stack_a)
{
	t_pushswap	*biggest;

	biggest = find_max(*stack_a);
	if (biggest == *stack_a)
		ra(stack_a, 0);
	else if ((*stack_a)->next == biggest)
		rra(stack_a, 0);
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a, 0);
}
