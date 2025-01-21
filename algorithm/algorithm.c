/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armirono <armirono@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:41:55 by armirono          #+#    #+#             */
/*   Updated: 2024/12/13 12:11:17 by armirono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_pushswap **a, t_pushswap **b, t_pushswap *chpst_node)
{
	while ((*b != chpst_node->target_node) && (*a != chpst_node))
		rr(a, b, 0);
	current_index(*a);
	current_index(*b);
}

static void	rev_rot_both(t_pushswap **a, t_pushswap **b, t_pushswap *chpst_node)
{
	while ((*b != chpst_node->target_node) && (*a != chpst_node))
		rrr(a, b, 0);
	current_index(*a);
	current_index(*b);
}

static void	move_a_to_b(t_pushswap **stack_a, t_pushswap **stack_b)
{
	t_pushswap	*chpst_nd;

	chpst_nd = get_cheapest(*stack_a);
	if (chpst_nd->above_median && chpst_nd->target_node->above_median)
		rotate_both(stack_a, stack_b, chpst_nd);
	else if (!(chpst_nd->above_median) &&!(chpst_nd->target_node->above_median))
		rev_rot_both(stack_a, stack_b, chpst_nd);
	prep_for_push(stack_a, chpst_nd, 'a');
	prep_for_push(stack_b, chpst_nd->target_node, 'b');
	pb(stack_b, stack_a, 0);
}

static void	min_on_top(t_pushswap **stack_a)
{
	while ((*stack_a)->value != find_min(*stack_a)->value)
	{
		if (find_min(*stack_a)->above_median)
			ra(stack_a, 0);
		else
			rra(stack_a, 0);
	}
}

void	algorithm(t_pushswap **a, t_pushswap **b)
{
	int	len_a;

	len_a = ft_lstsize(*a);
	if ((len_a-- > 3) && (!is_sorted(*a)))
		pb(b, a, 0);
	if ((len_a-- > 3) && (!is_sorted(*a)))
		pb(b, a, 0);
	while ((len_a-- > 3) && (!is_sorted(*a)))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_3(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		prep_for_push(a, (*b)->target_node, 'a');
		pa(a, b, 0);
	}
	current_index(*a);
	min_on_top(a);
}
