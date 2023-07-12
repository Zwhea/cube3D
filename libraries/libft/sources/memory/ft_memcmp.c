/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:28:57 by twang             #+#    #+#             */
/*   Updated: 2022/11/16 15:29:40 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1b;
	unsigned char	*s2b;

	if (n == 0)
		return (0);
	i = 0;
	s1b = (unsigned char *)s1;
	s2b = (unsigned char *)s2;
	while ((s1b[i] == s2b[i]) && (i < n - 1))
		i++;
	return (s1b[i] - s2b[i]);
}
