/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armirono <armirono@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:40:20 by armirono          #+#    #+#             */
/*   Updated: 2024/12/14 15:48:21 by armirono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	feed_args_from_string(t_pushswap **stack_a, char *argv1)
{
	int		i;
	char	**new_argv;

	i = 0;
	*stack_a = NULL;
	new_argv = new_split(argv1, ' ');
	if (!new_argv)
	{
		error_msg("Error: Failed to split arguments");
		return ;
	}
	init_stack_a(stack_a, new_argv);
	while (new_argv[i])
	{
		free(new_argv[i]);
		new_argv[i] = NULL;
		i++;
	}
	free(new_argv);
}

int	main(int argc, char **argv)
{
	t_pushswap	*stack_a;
	t_pushswap	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if ((argc == 1) || ((argc == 2) && !argv[1][0]))
		return (1);
	else if (argc == 2)
		feed_args_from_string(&stack_a, argv[1]);
	else
		init_stack_a(&stack_a, argv + 1);
	if (!is_sorted(stack_a))
	{
		if ((ft_lstsize(stack_a)) == 2)
			sa(&stack_a, 0);
		else if ((ft_lstsize(stack_a)) == 3)
			sort_3(&stack_a);
		else
			algorithm(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	return (0);
}
