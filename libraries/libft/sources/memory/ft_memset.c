/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:56:39 by twang             #+#    #+#             */
/*   Updated: 2023/10/13 11:01:06 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*array;

	i = 0;
	array = (unsigned char *)b;
	while (i < len)
	{
		array[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

float	*ft_memset_float(float	*b, float c, size_t len)
{
	size_t	i;
	float	*array;

	i = -1;
	array = b;
	while (++i < len)
		array[i] = c;
	return (b);
}
