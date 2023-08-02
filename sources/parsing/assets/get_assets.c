/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_assets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:40:26 by wangthea          #+#    #+#             */
/*   Updated: 2023/08/02 18:39:33 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

/*---- prototypes ------------------------------------------------------------*/

static void	_get_assets(t_game *g, char *line, t_keyassets asset_key);

/*----------------------------------------------------------------------------*/

void	which_asset(t_game *g, char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_iswhitespace(line[i]))
		i++;
	if (ft_strncmp(&line[i], "NO ", 3) == 0)
		return (_get_assets(g, line, north_texture));
	else if (ft_strncmp(&line[i], "SO ", 3) == 0)
		return (_get_assets(g, line, south_texture));
	else if (ft_strncmp(&line[i], "WE ", 3) == 0)
		return (_get_assets(g, line, west_texture));
	else if (ft_strncmp(&line[i], "EA ", 3) == 0)
		return (_get_assets(g, line, east_texture));
	else if (ft_strncmp(&line[i], "F ", 2) == 0)
		return (_get_assets(g, line, floor_color));
	else if (ft_strncmp(&line[i], "C ", 2) == 0)
		return (_get_assets(g, line, ceiling_color));
	return (_get_assets(g, line, no_asset));
}

static void	_get_assets(t_game *g, char *line, t_keyassets asset_key)
{
	const t_assets_ft	assets_tab[] = {&get_north_texture, &get_south_texture, \
										&get_west_texture, &get_east_texture, \
										&get_ceiling_color, &get_floor_color, \
										&error_asset};

	(*assets_tab[asset_key])(g, line);
}

void	error_asset(t_game *g, char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_iswhitespace(line[i]))
		i++;
	if (!line[i])
		return ;
	else
		error_switchman(g, texture_fail);
}
