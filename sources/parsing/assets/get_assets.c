/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_assets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:40:26 by wangthea          #+#    #+#             */
/*   Updated: 2023/08/02 22:38:18 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

/*---- prototypes ------------------------------------------------------------*/

static void	_get_assets(t_game *g, char *line, t_keyassets asset_key);

/*----------------------------------------------------------------------------*/

void	assets_switchman(t_game *game, char *line)
{
	int	i;

	i = 0;
	i += ft_skipwhitespace(i, line);
	
}
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
typedef void (*assets_function)(t_game *, char *);

// Structure pour associer une chaîne à un pointeur de fonction
typedef struct {
	const char		*asset;
	assets_function	func;
} assets_map;

// Tableau associant les chaînes aux fonctions

void asset_switchman(t_game *g, char *line)
{
	int	i;
	int	j;
	const assets_map assets_inv[] = {"NO ", &handle_north_texture},
									{"SO ", &handle_south_texture},
									{"WE ", &handle_west_texture},
									{"EA ", &handle_east_texture},
									{"F ", &handle_floor_color},
									{"C ", &handle_ceiling_color},
									{NULL, &handle_no_asset}
	i = 0;
	j = 0;
	i += ft_skipwhitespace(i, line);
	while (assets_inv[j].asset)
	{
		if (strncmp(&line[i], assets_inv[j].asset, ft_strlen(assets_inv[j].asset)) == 0) {
			assets_inv[j].func(g, line);
			return;
		}
		j++;
	}
	assets_inv[sizeof(assets_inv) / sizeof(assets_inv[0]) - 1].func(g, line);
}