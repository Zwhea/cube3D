/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:03:17 by wangthea          #+#    #+#             */
/*   Updated: 2023/08/11 16:13:11 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	_wrong_map(t_game *g)
{
	ft_error(false, WRONG_MAP);
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

void	_trapped_player(t_game *g)
{
	ft_error(false, "your player is trapped: fuck you.\n");
	clean(g);
}
