/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_doors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:48:03 by twang             #+#    #+#             */
/*   Updated: 2023/10/20 15:35:43 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*---- prototypes ------------------------------------------------------------*/

static void	_init_struct(t_game *g, int id, int i, int j);

/*----------------------------------------------------------------------------*/

void	set_doors(t_game *g)
{
	int	i;
	int	j;
	int	id;

	i = 0;
	id = 0;
	while (g->map.map[i])
	{
		j = 0;
		while (g->map.map[i][j])
		{
			if (g->map.map[i][j] == door)
			{
				_init_struct(g, id, i, j);
				id++;
			}
			j++;
		}
		i++;
	}
}

static void	_init_struct(t_game *g, int id, int i, int j)
{
	g->doors[id].pos.x = j;
	g->doors[id].pos.y = i;
	g->doors[id].move = 1.f;
	g->doors[id].status = neutral;
}
