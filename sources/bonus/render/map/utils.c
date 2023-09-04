/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:24:19 by wangthea          #+#    #+#             */
/*   Updated: 2023/09/04 09:15:38 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

int	door_direction(t_game *g, int x, int y)
{
	if (y < g->map.size.y && x < g->map.size.x \
			&& g->map.map[y][x] == door)
	{
		if (g->map.map[y - 1][x] == wall)
			return (0);
		else
			return (1);
	}
	else
		return (-1);
}