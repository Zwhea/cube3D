/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:24:19 by wangthea          #+#    #+#             */
/*   Updated: 2023/10/03 13:56:20 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

int	door_direction(t_game *g, int x, int y)
{
	if (y < g->map.size.y && x < g->map.size.x && g->map.map[y][x] == door)
	{
		if (g->map.map[y - 1][x] == wall && g->map.map[y + 1][x] == wall \
			&& g->map.map[y][x - 1] != wall && g->map.map[y][x + 1] != wall)
			return (0);
		else if (g->map.map[y - 1][x] != wall && g->map.map[y + 1][x] != wall \
			&& g->map.map[y][x - 1] == wall && g->map.map[y][x + 1] == wall)
			return (1);
	}
	return (-1);
}
