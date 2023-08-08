/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:46:50 by wangthea          #+#    #+#             */
/*   Updated: 2023/08/08 15:15:10 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

/*---- prototypes ------------------------------------------------------------*/

static void	_extract_ceiling_color(t_game *g, int i, char *line);
static void	_extract_floor_color(t_game *g, int i, char *line);

/*----------------------------------------------------------------------------*/

void	extract_nbrs(t_game *g, t_keyassets color_id, int i, char *line)
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
	{
		g->colors.rgb[0].r = ft_atoi(line);
		if (g->colors.rgb[0].r < 0 || g->colors.rgb[0].r > 255)
			error_switchman(g, wrong_color);
	}
	else if (i == 1)
	{
		g->colors.rgb[0].g = ft_atoi(line);
		if (g->colors.rgb[0].g < 0 || g->colors.rgb[0].g > 255)
			error_switchman(g, wrong_color);
	}
	else
	{
		g->colors.rgb[0].b = ft_atoi(line);
		if (g->colors.rgb[0].b < 0 || g->colors.rgb[0].b > 255)
			error_switchman(g, wrong_color);
	}
}

static void	_extract_floor_color(t_game *g, int i, char *line)
{
	if (i == 0)
	{
		g->colors.rgb[1].r = ft_atoi(line);
		if (g->colors.rgb[1].r < 0 || g->colors.rgb[1].r > 255)
			error_switchman(g, wrong_color);
	}
	else if (i == 1)
	{
		g->colors.rgb[1].g = ft_atoi(line);
		if (g->colors.rgb[1].g < 0 || g->colors.rgb[1].g > 255)
			error_switchman(g, wrong_color);
	}
	else
	{
		g->colors.rgb[1].b = ft_atoi(line);
		if (g->colors.rgb[1].b < 0 || g->colors.rgb[1].b > 255)
			error_switchman(g, wrong_color);
	}
}
