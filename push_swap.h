/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armirono <armirono@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:35:54 by armirono          #+#    #+#             */
/*   Updated: 2024/12/13 12:41:22 by armirono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_pushswap
{
	int					value;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_pushswap	*prev;
	struct s_pushswap	*target_node;
	struct s_pushswap	*next;
}	t_pushswap;

// General utility functions
long		ft_atol(const char *str);
int			ft_isnumber(char *num);
void		free_double_array(char **array);
void		free_stack(t_pushswap **stack);
void		error_msg(char *msg);
int			find_duplicates(t_pushswap *a, int n);
char		**new_split(char *s, char c);

//stack init

t_pushswap	*get_cheapest(t_pushswap *stack);
void		init_stack_a(t_pushswap **stack_a, char **argv);
t_pushswap	*get_cheapest(t_pushswap *stack);
void		prep_for_push(t_pushswap **stack, t_pushswap *top_node,
				char stack_name);
void		current_index(t_pushswap *stack);
void		set_cheapest(t_pushswap *stack);
void		init_nodes_a(t_pushswap *stack_a, t_pushswap *stack_b);
void		init_nodes_b(t_pushswap *stack_a, t_pushswap *stack_b);

// List function duplicates, since the struct is different from libft

int			ft_lstsize(t_pushswap *lst);
t_pushswap	*ft_lstlast(t_pushswap *head);
t_pushswap	*find_min(t_pushswap *stack);
t_pushswap	*find_max(t_pushswap *stack);
bool		is_sorted(t_pushswap *stack);

// Algorithm utility functions

void		algorithm(t_pushswap **stack_a, t_pushswap **stack_b);
void		sort_3(t_pushswap **stack_a);

// Moves

void		sa(t_pushswap **stack_a, bool print);
void		sb(t_pushswap **stack_b, bool print);
void		ss(t_pushswap **stack_a, t_pushswap **stack_b, bool print);
void		pa(t_pushswap **stack_a, t_pushswap **stack_b, bool print);
void		pb(t_pushswap **stack_b, t_pushswap **stack_a, bool print);
void		ra(t_pushswap **stack_a, bool print);
void		rb(t_pushswap **stack_b, bool print);
void		rr(t_pushswap **stack_a, t_pushswap **stack_b, bool print);
void		rra(t_pushswap **stack_a, bool print);
void		rrb(t_pushswap **stack_b, bool print);
void		rrr(t_pushswap **stack_a, t_pushswap **stack_b, bool print);

#endif
