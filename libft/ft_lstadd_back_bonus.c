/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armirono <armirono@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:14:52 by armirono          #+#    #+#             */
/*   Updated: 2024/12/10 23:07:00 by armirono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back_bonus(t_libft **lst, t_libft *new)
{
	if (lst && new)
	{
		if (*lst)
			ft_lstlast_bonus(*lst)->next = new;
		else
			*lst = new;
	}
}
