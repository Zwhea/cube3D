/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:43:47 by twang             #+#    #+#             */
/*   Updated: 2023/10/17 12:50:58 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"
#include "cub3D_arthur.h"

// /*---- prototypes ------------------------------------------------------------*/

// static void	_open_door(t_game *g, int id);
// static void	_close_door(t_game *g, int id);

// /*----------------------------------------------------------------------------*/

// int	get_id(t_game *g, int x, int y)
// {
// 	int	id;

// 	id = 0;
// 	while (id < g->sprites.nb_of_doors)
// 	{
// 		if (g->doors[id].pos.x == x && g->doors[id].pos.y == y)
// 			return (id);
// 		id++;
// 	}
// 	return (-1);
// }

// void	door_animations(t_game *g, int id)
// {
// 	if (!g->doors[id].is_open)
// 		_open_door(g, id);
// 	else
// 		_close_door(g, id);
// 	g->sprites.animation = false;
// }

// static void	_open_door(t_game *g, int id)
// {
// 	while (g->sprites.door_state[id] > 0)
// 	{
// 		if (!((g->sprites.door_state[id] - 0.01) < 0))
// 			g->sprites.door_state[id] -= 0.01;
// 		else
// 			break ;
// 	}
// 	g->sprites.door_state[id] = 0;
// 	g->map.map[g->door.check.y][g->door.check.x] = o_door;
// }

// static void	_close_door(t_game *g, int id)
// {
// 	while (g->sprites.door_state[id] < 1)
// 	{
// 		g->sprites.door_state[id] += 0.01;
// 	}
// 	g->sprites.door_state[id] = 1;
// 	g->map.map[g->door.check.y][g->door.check.x] = door;
// }
