/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrays.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 23:53:34 by wangthea          #+#    #+#             */
/*   Updated: 2023/08/02 15:47:29 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAYS_H
# define ARRAYS_H

/*---- includes --------------------------------------------------------------*/

# include "libft.h"

/*---- prototypes ------------------------------------------------------------*/

int		ft_arraylen(void **array);
int		*ft_range(int start, int end);
void	**ft_realloc_array(void **p, int height);
int		*ft_rrange(int start, int end);
void	sort_int_tab(int *tab, int size);

#endif