/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:46:50 by wangthea          #+#    #+#             */
/*   Updated: 2023/10/19 15:38:39 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*---- prototypes ------------------------------------------------------------*/

static void	_extract_ceiling_color(t_game *g, int i, char *line);
static void	_extract_floor_color(t_game *g, int i, char *line);

/*----------------------------------------------------------------------------*/

void	extract_colors(t_game *g, char *line, t_keyassets color_id)
{
	char	**color;
	int		id;

	color = ft_split(line, ',');
	if (!color)
		clean(g);
	id = 0;
	while (color[id])
	{
		extrct_nbrs(g, color_id, id, color[id]);
		id++;
	}
	free_split(color, 4);
}

void	extrct_nbrs(t_game *g, t_keyassets color_id, int i, char *line)
{
	if (color_id == ceiling_color)
		_extract_ceiling_color(g, i, line);
	else if (color_id == floor_color)
		_extract_floor_color(g, i, line);
}

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

static void	_extract_ceiling_color(t_game *g, int i, char *line)
{
	if (i == 0)
		g->color[0].r = ft_atoi(line);
	else if (i == 1)
		g->color[0].g = ft_atoi(line);
	else
		g->color[0].b = ft_atoi(line);
}

static void	_extract_floor_color(t_game *g, int i, char *line)
{
	if (i == 0)
		g->color[1].r = ft_atoi(line);
	else if (i == 1)
		g->color[1].g = ft_atoi(line);
	else
		g->color[1].b = ft_atoi(line);
}
