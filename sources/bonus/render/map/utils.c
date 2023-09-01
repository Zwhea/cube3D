/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:24:19 by wangthea          #+#    #+#             */
/*   Updated: 2023/09/01 15:55:09 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

int	door_direction(t_game *g, int x, int y)
{
	if (g->map.map[x][y] == door)
	{
		printf(RED"%c\n"END, g->map.map[x][y]);
		if (g->map.map[x][y - 1] == wall)
			return (1);
		else
			return (0);
	}
	else
		return (-1);
}