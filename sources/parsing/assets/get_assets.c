/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_assets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:40:26 by wangthea          #+#    #+#             */
/*   Updated: 2023/07/29 12:30:53 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

/*---- prototypes ------------------------------------------------------------*/

static int	_check_textures(t_game *g, char *file);
static int	_get_textures(t_game *g, char *file);
static int	_get_colors(t_game *g, char *file);

/*----------------------------------------------------------------------------*/

int	get_assets(t_game *g, char *file)
{
	if (_check_textures(g, file) == -1)
		return (-1);
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

static int	_check_textures(t_game *g, char *file)
{
	(void)g;
	(void)file;
	puts("je check les textures");
	return (0);
}

static int	_get_textures(t_game *g, char *file)
{
	(void)g;
	(void)file;
	puts("je get les textures");
	return (0);
}

static int	_get_colors(t_game *g, char *file)
{
	(void)g;
	(void)file;
	puts("je get les colors");
	return (0);
}
