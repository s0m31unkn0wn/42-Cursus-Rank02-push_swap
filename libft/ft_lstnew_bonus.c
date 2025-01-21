/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armirono <armirono@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:41:42 by armirono          #+#    #+#             */
/*   Updated: 2024/12/10 22:36:08 by armirono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_libft	*ft_lstnew_bonus(void *content)
{
	t_libft	*node;

	node = malloc(sizeof(t_libft));
	if (!node)
		return (0);
	node->content = content;
	node->next = 0;
	return (node);
}
