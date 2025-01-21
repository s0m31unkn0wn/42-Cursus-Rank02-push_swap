/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armirono <armirono@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 22:08:16 by armirono          #+#    #+#             */
/*   Updated: 2024/12/10 18:55:18 by armirono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_libft **lst, t_libft *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
