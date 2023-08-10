/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:29:45 by wangthea          #+#    #+#             */
/*   Updated: 2023/08/09 14:31:55 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_array(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		printf(BLUE"%s"END, array[i]);
	printf("\n");
}
