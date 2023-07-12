/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:58:02 by twang             #+#    #+#             */
/*   Updated: 2022/11/14 12:13:53 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;	

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	j = 0;
	i = dst_len;
	if (dstsize == 0 || dstsize <= dst_len)
		return (dstsize + src_len);
	while (src[j] && j < dstsize - dst_len - 1)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (src_len + dst_len);
}
