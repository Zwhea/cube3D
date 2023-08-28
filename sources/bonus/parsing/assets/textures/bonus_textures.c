/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:02:23 by twang             #+#    #+#             */
/*   Updated: 2023/08/28 16:23:39 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	handle_ceiling_texture(t_game *g, char *line)
{
	int		i;
	char	*s;

	i = 0;
	if (g->textures.bonus == false)
		return ;
	if (g->textures.walls[ceiling_texture].sprite)
		error_switchman(g, wrong_textures);
	while (line[i] && ft_strchr(TEXTURE_CEILING, line[i]))
		i++;
	s = &line[i];
	while (line[i] && !(ft_iswhitespace(line[i])))
		i++;
	if (line[i])
		line[i] = '\0';
	g->textures.walls[ceiling_texture].sprite = mlx_xpm_file_to_image(g->mlx, \
								s, &g->textures.size.x, &g->textures.size.y);
	g->textures.ceiling = true;
	return ;
}

void	handle_floor_texture(t_game *g, char *line)
{
	int		i;
	char	*s;

	i = 0;
	if (g->textures.bonus == false)
		return ;
	if (g->textures.walls[floor_texture].sprite)
		error_switchman(g, wrong_textures);
	while (line[i] && ft_strchr(TEXTURE_FLOOR, line[i]))
		i++;
	s = &line[i];
	while (line[i] && !(ft_iswhitespace(line[i])))
		i++;
	if (line[i])
		line[i] = '\0';
	g->textures.walls[floor_texture].sprite = mlx_xpm_file_to_image(g->mlx, s, \
									&g->textures.size.x, &g->textures.size.y);
	g->textures.floor = true;
	return ;
}
