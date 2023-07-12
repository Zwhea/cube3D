/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:11:39 by twang             #+#    #+#             */
/*   Updated: 2022/11/10 16:13:57 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*src2;
	unsigned char	*dst2;

	if (!dst && !src)
		return (NULL);
	src2 = (unsigned char *)src;
	dst2 = (unsigned char *)dst;
	if (src2 > dst2)
	{
		ft_memcpy(dst, src, len);
	}
	else
	{
		while (len--)
			dst2[len] = src2[len];
	}
	return (dst);
}
