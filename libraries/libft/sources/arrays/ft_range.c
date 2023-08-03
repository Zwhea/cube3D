/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 23:56:29 by wangthea          #+#    #+#             */
/*   Updated: 2023/08/02 17:16:03 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_range(int start, int end)
{
	int	*array;
	int	size;
	int	i;

	size = 0;
	if (start > end)
		size = (start - end);
	else if (start < end)
		size = (end - start);
	array = malloc((size + 1) * sizeof(int *));
	if (!array)
		return (NULL);
	i = -1;
	while (++i <= size)
	{
		if (start > end)
			array[i] = start--;
		else
			array[i] = start++;
	}
	return (array);
}
