/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_and_replace.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:56:56 by wangthea          #+#    #+#             */
/*   Updated: 2023/07/29 23:53:10 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*search_and_replace(char *string, char search, char replace)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == search)
			string[i] = replace;
		i++;
	}
	return (string);
}

//to test