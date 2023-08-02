/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:41:54 by twang             #+#    #+#             */
/*   Updated: 2023/08/02 17:15:11 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_realloc_array(void **p, int height)
{
	void	**pt;
	int		old_height;
	int		i;

	pt = NULL;
	old_height = ft_arraylen(p);
	i = 0;
	if (height > 0 && old_height < height)
	{
		pt = (void **)ft_calloc(height, sizeof(void *));
		if (p != NULL && pt != NULL)
		{
			while (i < old_height)
			{
				pt[i] = (void *)ft_calloc(ft_strlen(p[i]), sizeof(void));
				ft_memcpy(pt[i], p[i], ft_strlen(p[i]));
				ft_memdel(&p[i]);
				i++;
			}
			ft_memdel(p);
		}
	}
	return (pt);
}
