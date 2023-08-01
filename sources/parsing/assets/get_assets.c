/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_assets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:40:26 by wangthea          #+#    #+#             */
/*   Updated: 2023/08/01 16:34:07 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

/*---- prototypes ------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/

void	get_assets(t_game *g, char *line, t_keyassets asset_key)
{
	const t_assets_ft	assets_tab[] = {&get_north_texture, &get_south_texture,\
										&get_west_texture, &get_east_texture,\
										&get_ceiling_color, &get_floor_color,\
										&error_asset};
	// printf("%s", line);
	(*assets_tab[asset_key])(g, line);
}

void	get_north_texture(t_game *g, char *line)
{
	(void)g;
	int	i;

	i = 0;
	while (line[i] && ft_strchr(TEXTURE_NORTH, line[i]))
		i++;
	while (line[i] && line[i] != '\n')
	{
		printf("%c", line[i]);
		i++;
	}
	if (line[i] == '\n')
		puts("");
	return ;
}

void	get_south_texture(t_game *g, char *line)
{
	(void)g;
	int	i;

	i = 0;
	while (line[i] && ft_strchr(TEXTURE_SOUTH, line[i]))
		i++;
	while (line[i] && line[i] != '\n')
	{
		printf("%c", line[i]);
		i++;
	}
	if (line[i] == '\n')
		puts("");
	return ;
}

void	get_west_texture(t_game *g, char *line)
{
	(void)g;
	int	i;

	i = 0;
	while (line[i] && ft_strchr(TEXTURE_WEST, line[i]))
		i++;
	while (line[i] && line[i] != '\n')
	{
		printf("%c", line[i]);
		i++;
	}
	if (line[i] == '\n')
		puts("");
	return ;
}

void	get_east_texture(t_game *g, char *line)
{
	(void)g;
	int	i;

	i = 0;
	while (line[i] && ft_strchr(TEXTURE_EAST, line[i]))
		i++;
	while (line[i] && line[i] != '\n')
	{
		printf("%c", line[i]);
		i++;
	}
	if (line[i] == '\n')
		puts("");
	return ;
}

void	get_ceiling_color(t_game *g, char *line)
{
	(void)g;
	int	i;

	i = 0;
	while (line[i] && ft_strchr(COLOR_CEILING, line[i]))
		i++;
	while (line[i] && line[i] != '\n')
	{
		printf("%c", line[i]);
		i++;
	}
	if (line[i] == '\n')
		puts("");
	return ;
}

void	get_floor_color(t_game *g, char *line)
{
	(void)g;
	int	i;

	i = 0;
	while (line[i] && ft_strchr(COLOR_FLOOR, line[i]))
		i++;
	while (line[i] && line[i] != '\n')
	{
		printf("%c", line[i]);
		i++;
	}
	if (line[i] == '\n')
		puts("");
	return ;
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
