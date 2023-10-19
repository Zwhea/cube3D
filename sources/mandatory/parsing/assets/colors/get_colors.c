/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:37:45 by wangthea          #+#    #+#             */
/*   Updated: 2023/10/19 15:05:37 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	handle_ceiling_color(t_game *g, char *line)
{
	char	*s;
	int		i;

	i = 0;
	if (g->color[0].get)
	{
		free(line);
		error_switchman(g, wrong_colors);
	}
	while (line[i] && ft_strchr(COLOR_CEILING, line[i]))
		i++;
	s = &line[i];
	while (line[i] && !(ft_iswhitespace(line[i])))
		i++;
	if (line[i])
		line[i] = '\0';
	if (colors_checker(g, s))
	{
		free(line);
		error_switchman(g, wrong_color);
	}
	extract_colors(g, s, ceiling_color);
	g->color[0].color = create_rgb(g->color[0].r, g->color[0].g, g->color[0].b);
	g->color[0].get = true;
	return ;
}

void	handle_floor_color(t_game *g, char *line)
{
	int		i;
	char	*s;

	i = 0;
	if (g->color[1].get)
	{
		puts("je ne passe pas la");
		free(line);
		error_switchman(g, wrong_colors);
	}
	while (line[i] && ft_strchr(COLOR_FLOOR, line[i]))
		i++;
	s = &line[i];
	while (line[i] && !(ft_iswhitespace(line[i])))
		i++;
	if (line[i])
		line[i] = '\0';
	if (colors_checker(g, s))
	{
		free(line);
		error_switchman(g, wrong_color);
	}
	extract_colors(g, s, floor_color);
	g->color[1].color = create_rgb(g->color[1].r, g->color[1].g, g->color[1].b);
	g->color[1].get = true;
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
	{
		free(line);
		error_switchman(g, wrong_asset);
	}
}
