/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:09:15 by wangthea          #+#    #+#             */
/*   Updated: 2023/08/02 17:17:42 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTS_H
# define LISTS_H

/*---- includes --------------------------------------------------------------*/

# include "libft.h"

/*---- typedef structures ----------------------------------------------------*/

typedef struct s_list	t_list;
typedef struct s_lst	t_lst;

/*---- structures ------------------------------------------------------------*/

struct s_list
{
	void			*content;
	struct s_list	*next;
};

struct s_lst
{
	int				content;
	struct s_lst	*next;
};

/*---- prototypes ------------------------------------------------------------*/

void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);

void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstforeach(t_list *begin_list, void (*f)(void *));

void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstlast(t_list *lst);

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstnew(void *content);

void		ft_lstremove_if(t_list **begin_list, void *data_ref, int (*cmp)());
int			ft_lstsize(t_list *lst);
t_lst		*ft_lstsort(t_lst *lst, int (*cmp)(int, int));

#endif