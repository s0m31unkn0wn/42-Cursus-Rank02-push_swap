/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armirono <armirono@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:43:41 by armirono          #+#    #+#             */
/*   Updated: 2024/12/10 22:51:44 by armirono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_libft **lst, void (*del)(void *))
{
	t_libft	*next_list;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		next_list = (*lst)->next;
		ft_lstdelone_bonus(*lst, del);
		*lst = next_list;
	}
	free(*lst);
	*lst = 0;
}
