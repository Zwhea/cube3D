/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:24:19 by wangthea          #+#    #+#             */
/*   Updated: 2023/09/01 18:20:23 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

int	door_direction(t_game *g, int y, int x)
{
	if (y < g->map.size.y && x < g->map.size.x \
			&& g->map.map[y][x] == door)
	{
		if (g->map.map[y][x - 1] == wall)
			return (1);
		else
			return (0);
	}
	else
		return (-1);
}