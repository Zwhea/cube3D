/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 00:03:15 by wangthea          #+#    #+#             */
/*   Updated: 2023/08/02 17:17:27 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst	*ft_lstsort(t_lst *lst, int (*cmp)(int, int))
{
	int		swap;
	t_lst	*temp;

	temp = lst;
	while (lst->next != NULL)
	{
		if (((*cmp)(lst->content, lst->next->content)) == 0)
		{
			swap = lst->content;
			lst->content = lst->next->content;
			lst->next->content = swap;
			lst = temp;
		}
		else
			lst = lst->next;
	}
	lst = temp;
	return (lst);
}
