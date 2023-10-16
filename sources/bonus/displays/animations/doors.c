/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:43:47 by twang             #+#    #+#             */
/*   Updated: 2023/10/13 15:04:14 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"
#include "cub3D_arthur.h"

/*---- prototypes ------------------------------------------------------------*/

static int	_get_door_id(t_game *g, bool to_open);
static void	_open_door(t_game *g, int id);
static void	_close_door(t_game *g, int id);

/*----------------------------------------------------------------------------*/

int	door_animations(t_game *g)
{
	int	i;

	if (!g->sprites.is_open)
	{
		i = _get_door_id(g, true);
		_open_door(g, i);
	}
	else
	{
		i = _get_door_id(g, false);
		_close_door(g, i);
	}
	g->sprites.animation = false;
	return (i);
}

static int	_get_door_id(t_game *g, bool to_open)
{
	int		i;
	float	end;

	i = 0;
	end = 0.01;
	if (to_open)
		end = 0.999;
	while (g->sprites.door_state[i] < end)
		i++;
	return (i);
}

static void	_open_door(t_game *g, int id)
{
	while (g->sprites.door_state[id] > 0)
	{
		if (!((g->sprites.door_state[id] - 0.01) < 0))
			g->sprites.door_state[id] -= 0.01;
		else
			break ;
	}
	g->map.map[g->door.check.y][g->door.check.x] = o_door;
}

static void	_close_door(t_game *g, int id)
{
	while (g->sprites.door_state[id] < 1)
	{
		g->sprites.door_state[id] += 0.01;
	}
	g->map.map[g->door.check.y][g->door.check.x] = door;
}
