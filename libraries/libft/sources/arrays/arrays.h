/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrays.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 23:53:34 by wangthea          #+#    #+#             */
/*   Updated: 2023/07/30 00:10:23 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAYS_H
# define ARRAYS_H

/*---- includes --------------------------------------------------------------*/

# include "libft.h"

/*---- prototypes ------------------------------------------------------------*/

int		*ft_range(int start, int end);
int		*ft_rrange(int start, int end);
void	sort_int_tab(int *tab, int size);

#endif