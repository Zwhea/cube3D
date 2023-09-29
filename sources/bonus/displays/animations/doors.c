/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:43:47 by twang             #+#    #+#             */
/*   Updated: 2023/09/29 12:01:28 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"
#include "cub3D_arthur.h"

void	door_animations(t_game *g, int door_state)
{
	int	i;

	i = -1;
	while (++i < 500000)
	{
		g->map.map[g->ray.check.y][g->ray.check.x] = h_door;
		if (door_state)
			puts(GREEN"we need to open the door"END);
		else
			puts(RED"we need to close the door"END);
	}
}
