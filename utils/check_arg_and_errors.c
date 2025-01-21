/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_and_errors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armirono <armirono@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:45:18 by armirono          #+#    #+#             */
/*   Updated: 2024/12/13 13:45:07 by armirono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_duplicates(t_pushswap *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == n)
			return (1);
		a = a->next;
	}
	return (0);
}

int	ft_isnumber(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	error_msg(char *msg)
{
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

void	free_double_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	while (i > -1)
		free(array[i--]);
	free(array);
}

void	free_stack(t_pushswap **stack)
{
	t_pushswap	*current;
	t_pushswap	*temp;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		temp = current->next;
		current->value = 0;
		free(current);
		current = temp;
	}
	*stack = NULL;
}
