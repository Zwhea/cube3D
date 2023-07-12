/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:23:41 by twang             #+#    #+#             */
/*   Updated: 2022/11/16 15:07:45 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	s_lenght(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	length;

	i = 0;
	length = 0;
	while (s[i] && length < len)
	{
		if (i >= start)
			length++;
		i++;
	}
	return (length);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	length;
	char	*substr_s;

	if (!s)
		return (NULL);
	length = s_lenght((char *)s, start, len);
	substr_s = ft_calloc(length + 1, sizeof(char));
	if (!substr_s)
		return (NULL);
	i = 0;
	while (i < length)
		substr_s[i++] = s[start++];
	return (substr_s);
}
