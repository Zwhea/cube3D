/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_movable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:00:07 by twang             #+#    #+#             */
/*   Updated: 2023/09/28 10:20:05 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_x(t_game *g, int next_x)
{
	if (g->map.map[(int)g->player.posf.y][(int)next_x] != wall)
		return (1);
	return (0);
}

int	check_y(t_game *g, int next_y)
{
	if (g->map.map[(int)next_y][(int)g->player.posf.x] != wall)
		return (1);
	return (0);
}
