/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:43:47 by twang             #+#    #+#             */
/*   Updated: 2023/10/19 10:19:26 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"
#include "cub3D_arthur.h"

/*---- prototypes ------------------------------------------------------------*/

static void	_open_door(t_game *g, int id);
static void	_close_door(t_game *g, int id);

/*----------------------------------------------------------------------------*/

int	get_id(t_game *g, int x, int y)
{
	int	id;

	id = 0;
	while (id < g->sprites.nb_of_doors)
	{
		if (g->doors[id].pos.x == x && g->doors[id].pos.y == y)
			return (id);
		id++;
	}
	return (-1);
}

void	door_animations(t_game *g)
{
	int	id;

	id = -1;
	while (++id < g->sprites.nb_of_doors)
	{
		if (g->doors[id].status == opening)
		{
			
			printf("%f\n", g->doors[1].status);
			_open_door(g, id);
		}
		else if (g->doors[id].status == closing)
			_close_door(g, id);
	}
}

static void	_open_door(t_game *g, int id)
{
	if (!((g->doors[id].move - 0.01) < 0))
		g->doors[id].move -= 0.01;
	else
	{
		g->doors[id].status = neutral;
		g->doors[id].move = 0.f;
		g->map.map[g->doors[id].pos.y][g->doors[id].pos.x] = o_door;
	}
	return ;
}

static void	_close_door(t_game *g, int id)
{
	if (!((g->doors[id].move + 0.01) > 1))
		g->doors[id].move += 0.01;
	else
	{
		g->doors[id].status = neutral;
		g->doors[id].move = 1.f;
		g->map.map[g->doors[id].pos.y][g->doors[id].pos.x] = door;
	}
	return ;
}
