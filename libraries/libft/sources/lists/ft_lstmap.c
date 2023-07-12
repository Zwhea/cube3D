/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:31:57 by wangthea          #+#    #+#             */
/*   Updated: 2022/11/18 18:17:50 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp_new;

	if (!lst || !f)
		return (NULL);
	new = ft_lstnew((f(lst->content)));
	if (!new)
	{
		ft_lstclear(&new, del);
		return (NULL);
	}
	lst = lst->next;
	temp_new = new;
	while (lst)
	{
		temp_new->next = ft_lstnew(f(lst->content));
		if (!temp_new->next)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		temp_new = temp_new->next;
		lst = lst->next;
	}
	return (new);
}
