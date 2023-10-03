/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:02:23 by twang             #+#    #+#             */
/*   Updated: 2023/09/28 08:47:00 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	handle_ceiling_texture(t_game *g, char *line)
{
	int		i;
	char	*s;

	i = 0;
	if (g->textures.bonus == false)
	{
		free(line);
		error_switchman(g, wrong_texture);
	}
	if (g->textures.walls[ceiling_texture].img)
	{
		free(line);
		error_switchman(g, wrong_textures);
	}
	while (line[i] && ft_strchr(TEXTURE_CEILING, line[i]))
		i++;
	s = &line[i];
	while (line[i] && !(ft_iswhitespace(line[i])))
		i++;
	if (line[i])
		line[i] = '\0';
	g->textures.walls[ceiling_texture].img = mlx_xpm_file_to_image(g->mlx, s, \
		&g->textures.walls[ceiling_texture].width, &g->textures.walls[ceiling_texture].height);
	g->textures.ceiling = true;
	return ;
}

void	handle_floor_texture(t_game *g, char *line)
{
	int		i;
	char	*s;

	i = 0;
	if (g->textures.bonus == false)
	{
		free(line);
		error_switchman(g, wrong_texture);
	}
	if (g->textures.walls[floor_texture].img)
		error_switchman(g, wrong_textures);
	while (line[i] && ft_strchr(TEXTURE_FLOOR, line[i]))
		i++;
	s = &line[i];
	while (line[i] && !(ft_iswhitespace(line[i])))
		i++;
	if (line[i])
		line[i] = '\0';
	g->textures.walls[floor_texture].img = mlx_xpm_file_to_image(g->mlx, s, \
									&g->textures.walls[floor_texture].width, &g->textures.walls[floor_texture].height);
	g->textures.floor = true;
	return ;
}
