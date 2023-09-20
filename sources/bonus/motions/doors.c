/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 09:39:28 by twang             #+#    #+#             */
/*   Updated: 2023/09/20 10:28:18 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"
#include "cub3D_arthur.h"

/*---- prototypes ------------------------------------------------------------*/

static int		_check_direction(double angle);
static void		_check_door(t_game *g, int y, int x);

/*----------------------------------------------------------------------------*/

int	open_door(t_game *g)
{
	if (_check_direction(g->player.angle_view) == 0)
		_check_door(g, g->player.pos.y - 1, g->player.pos.x);
	if (_check_direction(g->player.angle_view) == 1)
		_check_door(g, g->player.pos.y + 1, g->player.pos.x);
	if (_check_direction(g->player.angle_view) == 2)
		_check_door(g, g->player.pos.y, g->player.pos.x - 1);
	if (_check_direction(g->player.angle_view) == 3)
		_check_door(g, g->player.pos.y, g->player.pos.x + 1);
	return (0);
}

static int	_check_direction(double angle)
{
	double	pov;

	pov = remainder(angle, (2 * M_PI));
	if ((pov > 5 * M_PI / 4 && pov < 7 * M_PI / 4) \
			|| (pov > -3 * M_PI / 4 && pov < -M_PI_4))
		return (0);
	if ((pov > M_PI_4 && pov < 3 * M_PI / 4) \
			|| (pov > -7 * M_PI / 4 && pov < -5 * M_PI / 4))
		return (1);
	if ((pov > 3 * M_PI / 4 && pov < 5 * M_PI / 4) \
			|| (pov > -5 * M_PI / 4 && pov < -3 * M_PI / 4))
		return (2);
	if ((pov > -M_PI_4 && pov < M_PI_4) \
			|| (pov > -7 * M_PI / 4 && pov < -2 * M_PI))
		return (3);
	return (-1);
}

static void	_check_door(t_game *g, int y, int x)
{
	if (g->map.map[y][x] == door)
	{
		g->map.map[y][x] = o_door;
		map_render(g);
	}
	else if (g->map.map[y][x] == o_door)
	{
		g->map.map[y][x] = door;
		map_render(g);
	}
}
