/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:43:47 by twang             #+#    #+#             */
/*   Updated: 2023/10/13 11:33:29 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"
#include "cub3D_arthur.h"

/*---- prototypes ------------------------------------------------------------*/

static int	_open_door(t_game *g);
static int	_close_door(t_game *g);

/*----------------------------------------------------------------------------*/

int	door_animations(t_game *g)
{
	int	i;
	
	if (!g->sprites.is_open)
		i = _open_door(g);
	else
		i = _close_door(g);
	g->sprites.animation = false;
	return (i);
}

static int	_open_door(t_game *g)
{
	int	i;

	i = 0;
	while (g->sprites.door_state[i] < 0.999)
		i++;
	while (g->sprites.door_state[i] > 0)
	{
		if (!((g->sprites.door_state[i] - 0.01) < 0))
			g->sprites.door_state[i] -= 0.01;
		else
			break ;
	}
	g->map.map[g->door.check.y][g->door.check.x] = o_door;
	return (i);
}

static int	_close_door(t_game *g)
{
	int	i;

	i = 0;
	while (g->sprites.door_state[i] > 0.01)
		i++;
	while (g->sprites.door_state[i] < 1)
	{
		g->sprites.door_state[i] += 0.01;
	}
	g->map.map[g->door.check.y][g->door.check.x] = door;
	return (i);
}
