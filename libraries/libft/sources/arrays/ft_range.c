/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 23:56:29 by wangthea          #+#    #+#             */
/*   Updated: 2023/07/29 23:56:33 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_range(int start, int end)
{
	int	*array;
	int size;
	int	i;

	size = 0;
	if (start > end)
		size = (start - end);
	else if (start < end)
		size = (end - start);
	array = malloc((size + 1) * sizeof(int *));
	if (!array)
		return (NULL);
	i = 0;
	while (i <= size)
	{
		if (start > end)
		{
			array[i] = start;
			start--;
			i++;
		}
		else
		{
			array[i] = start;
			start++;
			i++;
		}
	}
	return (array);
}
