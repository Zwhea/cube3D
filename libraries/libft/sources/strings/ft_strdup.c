/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:08:43 by twang             #+#    #+#             */
/*   Updated: 2022/11/14 11:39:54 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		size;
	char	*s1b;
	char	*s1_duplicate;

	i = 0;
	size = ft_strlen(s1);
	s1b = (char *)s1;
	s1_duplicate = malloc(sizeof(char) * size + 1);
	if (!s1_duplicate)
		return (NULL);
	while (s1b[i])
	{
		s1_duplicate[i] = s1b[i];
		i ++;
	}
	s1_duplicate[i] = '\0';
	return (s1_duplicate);
}
