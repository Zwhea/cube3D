/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:37:45 by wangthea          #+#    #+#             */
/*   Updated: 2023/08/09 14:47:34 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	handle_ceiling_color(t_game *g, char *line)
{
	char	*s;
	int		i;

	i = 0;
	while (line[i] && ft_strchr(COLOR_CEILING, line[i]))
		i++;
	s = &line[i];
	while (line[i] && !(ft_iswhitespace(line[i])))
		i++;
	if (line[i])
		line[i] = '\0';
	colors_checker(g, s);
	extract_colors(g, s, ceiling_color);
	g->colors.rgb[0].color = create_rgb(g->colors.rgb[0].r, g->colors.rgb[0].g, g->colors.rgb[0].b);
	return ;
}

void	handle_floor_color(t_game *g, char *line)
{
	int		i;
	char	*s;

	i = 0;
	while (line[i] && ft_strchr(COLOR_FLOOR, line[i]))
		i++;
	s = &line[i];
	while (line[i] && !(ft_iswhitespace(line[i])))
		i++;
	if (line[i])
		line[i] = '\0';
	colors_checker(g, s);
	extract_colors(g, s, floor_color);
	g->colors.rgb[1].color = create_rgb(g->colors.rgb[1].r, g->colors.rgb[1].g, g->colors.rgb[1].b);
	return ;
}

void	handle_no_asset(t_game *g, char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_iswhitespace(line[i]))
		i++;
	if (!line[i])
		return ;
	else
		error_switchman(g, wrong_asset);
}
