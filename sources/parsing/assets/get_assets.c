/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_assets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:40:26 by wangthea          #+#    #+#             */
/*   Updated: 2023/07/24 17:27:53 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

/*---- prototypes ------------------------------------------------------------*/

static int	_get_textures(t_game *g, char *file);
static int	_get_colors(t_game *g, char *file);

/*----------------------------------------------------------------------------*/

int	get_assets(t_game *g, char *file)
{
	if (_get_textures(g, file) == -1)
	{
		error_switchman(g, texture_fail);
		return (-1);
	}
	if (_get_colors(g, file) == -1)
	{
		error_switchman(g, color_fail);
		return (-1);
	}
	return (0);
}

static int	_get_textures(t_game *g, char *file)
{
	(void)g;
	(void)file;
	/*
	get_north_texture();
	get_south_texture();
	get_west_texture();
	get_east_texture();
	*/
	return (-1);
}

static int	_get_colors(t_game *g, char *file)
{
	(void)g;
	(void)file;
	/*
	get_floor_color();
	get_ceiling_color();
	*/
	return (-1);
}

