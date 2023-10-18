/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:03:17 by wangthea          #+#    #+#             */
/*   Updated: 2023/08/31 13:54:04 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	_wrong_map(t_game *g)
{
	ft_error(false, WRONG_MAP);
	if (g->map.b_map)
		free_split(g->map.b_map, g->map.size.y);
	clean(g);
}

void	_wrong_char(t_game *g)
{
	ft_error(false, WRONG_CHAR);
	clean(g);
}

void	_wrong_player(t_game *g)
{
	ft_error(false, WRONG_PLAYER);
	clean(g);
}
