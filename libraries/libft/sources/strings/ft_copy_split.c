/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:43:35 by wangthea          #+#    #+#             */
/*   Updated: 2023/08/08 16:53:48 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_copy_split(char **src, char **dst)
{
	int	i;

	dst = (char **)ft_calloc(ft_arraylen((void **)src), sizeof(char *));
	if (!dst)
		return (NULL);
	i = -1;
	while (src[++i])
	{
		dst[i] = ft_strdup(src[i]);
	}
	return (dst);
}