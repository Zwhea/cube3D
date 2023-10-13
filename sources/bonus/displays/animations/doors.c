/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:43:47 by twang             #+#    #+#             */
/*   Updated: 2023/10/12 15:48:52 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"
#include "cub3D_arthur.h"

/*---- prototypes ------------------------------------------------------------*/

static void	_open_door(t_game *g);
static void	_close_door(t_game *g);

/*----------------------------------------------------------------------------*/

void	door_animations(t_game *g)
{
	if (!g->sprites.is_open)
		_open_door(g);
	else
		_close_door(g);
	g->sprites.animation = false;
}

static void	_open_door(t_game *g)
{
	float	door_state;

	door_state = 1;
	while (door_state > 0)
	{
		door_state -= 0.01;
		printf(GREEN"%f\n"END, door_state);
	}
	g->map.map[g->door.check.y][g->door.check.x] = o_door;
}

static void	_close_door(t_game *g)
{
	float	door_state;

	door_state = 0;
	while (door_state < 1)
	{
		door_state += 0.01;
		printf(RED"%f\n"END, door_state);
	}
	g->map.map[g->door.check.y][g->door.check.x] = door;
}
