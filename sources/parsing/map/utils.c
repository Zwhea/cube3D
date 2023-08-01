/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:04:52 by twang             #+#    #+#             */
/*   Updated: 2023/08/01 10:05:35 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

bool	is_map(char *line)
{
	int	i;
	int	player;

	i = 0;
	player = 0;
	if (line[i] == '\n')
		return (false);
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != ' ' && line[i] != '\n')
		{
			if (line[i] == 'N' || line[i] == 'W' || line[i] == 'E' || line[i] == 'S')
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