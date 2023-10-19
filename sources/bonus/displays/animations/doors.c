/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:43:47 by twang             #+#    #+#             */
/*   Updated: 2023/10/19 10:58:38 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"
#include "cub3D_arthur.h"

/*---- prototypes ------------------------------------------------------------*/

static float	_open_door(t_game *g, int id, float ratio);
static float	_close_door(t_game *g, int id, float ratio);

/*----------------------------------------------------------------------------*/

int	get_id(t_game *g, int x, int y)
{
	int	id;

	id = 0;
	while (id < g->sprites.nb_of_doors)
	{
		if (g->doors[id].pos.x == x && g->doors[id].pos.y == y)
		{
			g->id = id;
			return (id);
		}
		id++;
	}
	return (-1);
}

void	door_animations(t_game *g)
{
	int		id;
	float	ratio;

	id = -1;
	ratio = 0.01;
	while (++id < g->sprites.nb_of_doors)
	{
		if (g->doors[id].status == opening)
			_open_door(g, id, ratio);
		else if (g->doors[id].status == closing)
			_close_door(g, id, ratio);
	}
}

static float	_open_door(t_game *g, int id, float ratio)
{
	if (!((g->doors[id].move - sin(g->doors[id].move))) < 0)
		g->doors[id].move -= sin(g->doors[id].move;
	else
	{
		g->doors[id].status = neutral;
		g->doors[id].move = 0.f;
		g->map.map[g->doors[id].pos.y][g->doors[id].pos.x] = o_door;
	}
	return (2 * ratio + 0.01);
}

static float	_close_door(t_game *g, int id, float ratio)
{
	if (!((g->doors[id].move + 0.01) > 1))
		g->doors[id].move += 0.01;
	else
	{
		g->doors[id].status = neutral;
		g->doors[id].move = 1.f;
		g->map.map[g->doors[id].pos.y][g->doors[id].pos.x] = door;
	}
	return (2 * ratio + 0.01);
}
