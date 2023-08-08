/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:19:40 by twang             #+#    #+#             */
/*   Updated: 2023/08/08 17:00:45 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

/*---- prototypes ------------------------------------------------------------*/

static void	_check_char(t_game *g);
static void	_backtracking(t_game *g, int x, int y);

/*----------------------------------------------------------------------------*/

void	map_checker(t_game *g)
{
	_check_char(g);
	if (g->player.player != 1)
		error_switchman(g, wrong_player);
	ft_copy_split(g->map.map, g->map.b_map);
	_backtracking(g, g->player.pos.x, g->player.pos.y);
	// free_split(g->map.b_map, g->map.size.y);
}

static void	_check_char(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (g->map.map[++i])
	{
		if (ft_isempty(g->map.map[i]))
			error_switchman(g, wrong_map);
		set_map_width(g, g->map.map[i]);
		j = -1;
		while (g->map.map[i][++j])
		{
			if (!ft_strchr(MAP_CHARSET, g->map.map[i][j]))
				error_switchman(g, wrong_char);
			if (ft_strchr(PLAYER_CHARSET, g->map.map[i][j]))
			{
				g->player.player++;
				set_direction(g, g->map.map[i][j]);
				set_vector(&g->player.pos, i, j);
			}
		}
	}
}

static void	_backtracking(t_game *g, int x, int y)
{
	// if (i - 1 > 0 && y -1 > 0)
	//du coup test ->
	if (g->map.line_len[x + 1] <= y || g->map.line_len[x - 1] <= y \
		|| g->map.map[x + 1][y] == empty || g->map.map[x - 1][y] == empty \
		|| g->map.map[x][y + 1] == empty || g->map.map[x][y - 1] == empty)
		error_switchman(g, wrong_map);
	if (g->map.map[x][y + 1] != wall)
	{
		g->map.map[x][y + 1] = wall;
		_backtracking(g, x, y + 1);
	}
	if (g->map.map[x][y - 1] != wall)
	{
		g->map.map[x][y - 1] = wall;
		_backtracking(g, x, y - 1);
	}
	if (g->map.map[x + 1][y] != wall)
	{
		g->map.map[x + 1][y] = wall;
		_backtracking(g, x + 1, y);
	}
	if (g->map.map[x - 1][y] != wall)
	{
		g->map.map[x - 1][y] = wall;
		_backtracking(g, x - 1, y);
	}
	g->map.map[x][y] = wall;
}
