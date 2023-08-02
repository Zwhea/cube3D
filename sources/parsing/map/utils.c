/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:04:52 by twang             #+#    #+#             */
/*   Updated: 2023/08/02 18:41:49 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

bool	is_map(char *s)
{
	int	i;
	int	player;

	i = 0;
	player = 0;
	if (s[i] == '\n')
		return (false);
	while (s[i])
	{
		if (s[i] != '0' && s[i] != '1' && s[i] != ' ' && s[i] != '\n')
		{
			if (s[i] == 'N' || s[i] == 'W' || s[i] == 'E' || s[i] == 'S')
				player++;
			else
				return (false);
		}
		i++;
	}
	if (player > 1)
		return (false);
	return (true);
}
