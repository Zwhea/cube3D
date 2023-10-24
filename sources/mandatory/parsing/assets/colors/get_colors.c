/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:37:45 by wangthea          #+#    #+#             */
/*   Updated: 2023/10/24 10:47:12 by twang            ###   ########.fr       */
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
	while (line[i])
		i++;
	if (line[i])
		line[i] = '\0';
	if (colors_checker(g, s))
	{
		free(line);
		error_switchman(g, wrong_color);
	}
	extract_colors(g, s, ceiling_color, line);
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
		free(line);
		error_switchman(g, wrong_colors);
	}
	while (line[i] && ft_strchr(COLOR_FLOOR, line[i]))
		i++;
	s = &line[i];
	while (line[i])
		i++;
	if (line[i])
		line[i] = '\0';
	if (colors_checker(g, s))
	{
		free(line);
		error_switchman(g, wrong_color);
	}
	extract_colors(g, s, floor_color, line);
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

int	colors_checker(t_game *g, char *line)
{
	int	comma_nb;
	int	i;

	(void)g;
	comma_nb = 0;
	i = -1;
	while (line[++i] && ft_strchr(COLOR_CHARSET, line[i]))
	{
		if (line[i] == ',')
			comma_nb++;
	}
	if ((line[i] != '\0' && line[i] != '\n') || comma_nb != 2)
		return (1);
	return (0);
}

void	extract_colors(t_game *g, char *line, t_keyassets color_id, char *str)
{
	char	**color;
	int		id;

	color = ft_split(line, ',');
	if (!color)
		clean(g);
	id = 0;
	while (color[id])
	{
		if (extrct_nbrs(g, color_id, id, color[id]))
		{
			free(str);
			free_split(color, ft_arraylen((void **)color));
			error_switchman(g, wrong_color);
		}
		id++;
	}
	if (id != 3)
	{
		free_split(color, ft_arraylen((void **)color));
		error_switchman(g, wrong_color);
	}
	free_split(color, ft_arraylen((void **)color));
}
