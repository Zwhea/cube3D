/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:02:59 by wangthea          #+#    #+#             */
/*   Updated: 2023/09/26 15:59:08 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	_wrong_asset(t_game *g)
{
	(void)g;
	ft_error(false, WRONG_ASSET);
}

void	_wrong_texture(t_game *g)
{
	ft_error(false, WRONG_TEXTURE);
	// close_file(g->file.fd);
	clean(g);
}

void	_wrong_textures(t_game *g)
{
	ft_error(false, WRONG_TEXTURES);
	// close_file(g->file.fd);
	clean(g);
}

void	_wrong_color(t_game *g)
{
	ft_error(false, WRONG_COLOR);
	clean(g);
}

void	_wrong_colors(t_game *g)
{
	ft_error(false, WRONG_COLORS);
	clean(g);
}
