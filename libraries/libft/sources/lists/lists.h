/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:09:15 by wangthea          #+#    #+#             */
/*   Updated: 2023/07/12 14:10:10 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTS_H
# define LISTS_H

/*---- includes --------------------------------------------------------------*/

# include "libft.h"

/*---- typedef structures ----------------------------------------------------*/

typedef struct s_list	t_list;

/*---- structures ------------------------------------------------------------*/

struct s_list
{
	void			*content;
	struct s_list	*next;
};

/*---- prototypes ------------------------------------------------------------*/

void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);

void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstdelone(t_list *lst, void (*del)(void*));

void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstlast(t_list *lst);

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstnew(void *content);

int			ft_lstsize(t_list *lst);

#endif