/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:21:43 by twang             #+#    #+#             */
/*   Updated: 2022/11/14 09:58:51 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*hayst;
	char	*needl;

	i = 0;
	hayst = (char *)haystack;
	needl = (char *)needle;
	if (!needl[i])
		return (hayst);
	while (i < len && hayst[i])
	{
		j = 0;
		while (hayst[i + j] == needl[j] && i + j < len)
		{
			if (needl[j + 1] == '\0')
				return ((char *) &hayst[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
