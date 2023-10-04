/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove_if.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 00:02:12 by wangthea          #+#    #+#             */
/*   Updated: 2023/09/26 15:00:46 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	ft_lstremove_if(t_list **begin_list, void *data_ref, int (*cmp)())
// {
// 	t_list	*lst_ptr;

// 	if (begin_list == 0 || *begin_list == 0)
// 		return ;
// 	lst_ptr = *begin_list;
// 	if (cmp(lst_ptr->content, data_ref) == 0)
// 	{
// 		*begin_list = lst_ptr->next;
// 		free(lst_ptr);
// 		ft_lstremove_if(begin_list, data_ref, cmp);
// 	}
// 	ft_lstremove_if(&lst_ptr->next, data_ref, cmp);
// }
