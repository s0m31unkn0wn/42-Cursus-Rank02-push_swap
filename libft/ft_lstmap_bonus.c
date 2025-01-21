/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armirono <armirono@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:51:20 by armirono          #+#    #+#             */
/*   Updated: 2024/12/13 12:14:07 by armirono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_libft	*ft_lstmap_bonus(t_libft *lst, void *(*f)(void *), void (*del)(void *))
{
	t_libft	*new_list;
	t_libft	*temp;
	void	*argument;

	new_list = 0;
	if (!f || !del)
		return (new_list);
	while (lst)
	{
		argument = f(lst->content);
		temp = ft_lstnew_bonus(f(lst->content));
		if (!temp)
		{
			free(argument);
			ft_lstclear_bonus(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back_bonus(&new_list, temp);
		lst = lst->next;
	}
	return (new_list);
}
