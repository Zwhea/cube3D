/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_movable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:00:07 by twang             #+#    #+#             */
/*   Updated: 2023/10/20 15:39:30 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_x(t_game *g, int next_x)
{
	if (g->doors[g->id].status == closing)
		return (0);
	if (g->map.map[(int)g->player.posf.y][(int)next_x] != wall \
			&& g->map.map[(int)g->player.posf.y][(int)next_x] != door)
		return (1);
	return (0);
}

int	check_y(t_game *g, int next_y)
{
	if (g->doors[g->id].status == closing)
		return (0);
	if (g->map.map[(int)next_y][(int)g->player.posf.x] != wall \
			&& g->map.map[(int)next_y][(int)g->player.posf.x] != door)
		return (1);
	return (0);
}
