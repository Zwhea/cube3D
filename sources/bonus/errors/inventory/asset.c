/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:02:59 by wangthea          #+#    #+#             */
/*   Updated: 2023/08/11 15:43:13 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	_wrong_asset(t_game *g)
{
	ft_error(false, WRONG_ASSET);
	if (g->file.fd)
		close(g->file.fd);
	clean(g);
}

void	_wrong_texture(t_game *g)
{
	ft_error(false, WRONG_TEXTURE);
	if (g->file.fd)
		close(g->file.fd);
	clean(g);
}

void	_wrong_textures(t_game *g)
{
	ft_error(false, WRONG_TEXTURES);
	if (g->file.fd)
		close(g->file.fd);
	clean(g);
}

void	_wrong_color(t_game *g)
{
	ft_error(false, WRONG_COLOR);
	if (g->file.fd)
		close(g->file.fd);
	clean(g);
}

void	_wrong_colors(t_game *g)
{
	ft_error(false, WRONG_COLORS);
	if (g->file.fd)
		close(g->file.fd);
	clean(g);
}
