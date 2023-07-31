/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_assets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:40:26 by wangthea          #+#    #+#             */
/*   Updated: 2023/07/31 11:37:14 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

/*---- prototypes ------------------------------------------------------------*/

static int	_get_textures(t_game *g);
static int	_get_colors(t_game *g);

/*----------------------------------------------------------------------------*/

int	get_assets(t_game *g)
{
	if (check_textures(g) == -1)
		return (-1);
	if (_get_textures(g) == -1)
	{
		error_switchman(g, texture_fail);
		return (-1);
	}
	if (check_colors(g) == -1)
		return (-1);
	if (_get_colors(g) == -1)
	{
		error_switchman(g, color_fail);
		return (-1);
	}
	return (0);
}

static int	_get_textures(t_game *g)
{
	(void)g;
	puts("je get les textures");
	return (0);
}

static int	_get_colors(t_game *g)
{
	(void)g;
	puts("je get les colors");
	return (0);
}
