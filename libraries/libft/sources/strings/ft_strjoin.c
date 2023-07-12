/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:58:30 by twang             #+#    #+#             */
/*   Updated: 2022/11/15 12:15:04 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	s_length(char *s1, char *s2)
{
	size_t	join_length;
	size_t	s1_length;
	size_t	s2_length;

	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	join_length = s1_length + s2_length;
	return (join_length);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	length;
	char	*s_join;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	length = s_length((char *)s1, (char *)s2);
	s_join = ft_calloc(length + 1, sizeof(char));
	if (!s_join)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		s_join[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		s_join[i] = s2[j];
		i++;
		j++;
	}
	return (s_join);
}
