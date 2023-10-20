/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 08:46:47 by aascedu           #+#    #+#             */
/*   Updated: 2023/10/20 15:39:52 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*---- prototypes ------------------------------------------------------------*/

static void	_init_minimap(t_game *g, t_minimap *mini);
static void	_start_minimap(t_game *g, t_minimap *mini);
static void	_draw_minimap(t_game *g, int center, t_vector_f indic, \
															t_vector_f monitor);
static void	_rotate(t_game *g, t_vector_f *indic);

/*----------------------------------------------------------------------------*/

void	minimap_display(t_game *g)
{
	t_vector	player;

	set_vector(&player, TILE * 7, TILE * 7);
	_init_minimap(g, &g->mini_map);
	_start_minimap(g, &g->mini_map);
	ray_minimap(g, &g->mini_map);
	draw_circle(g, &player, 6, H_DARKGREEN);
	draw_north(g);
}

static void	_init_minimap(t_game *g, t_minimap *mini)
{
	mini->center = TILE * 7;
	mini->rayon = TILE * 6;
	set_vector_f(&mini->indic, (-1) * mini->rayon, (-1) * mini->rayon);
	set_vector_f(&mini->monitor, g->player.posf.x - 6, g->player.posf.y - 6);
	mini->ratio = 0.5 / TILE;
	while (mini->monitor.y < 0)
	{
		mini->monitor.y += mini->ratio;
		mini->indic.y += 0.5;
	}
	while (mini->monitor.x < 0)
	{
		mini->monitor.x += mini->ratio;
		mini->indic.x += 0.5;
	}
	mini->monitor_start = mini->monitor.x;
	mini->indic_start = mini->indic.x;
}

static void	_start_minimap(t_game *g, t_minimap *mini)
{
	while (mini->indic.y < mini->rayon && mini->monitor.y < g->map.size.y)
	{
		mini->indic.x = mini->indic_start;
		mini->monitor.x = mini->monitor_start;
		while (mini->monitor.x < g->map.size.x && mini->indic.x < mini->rayon \
				&& g->map.mini_map[(int)mini->monitor.y][(int)mini->monitor.x])
		{
			if ((mini->indic.x * mini->indic.x) \
				+ (mini->indic.y * mini->indic.y) \
				< (mini->rayon * mini->rayon))
				_draw_minimap(g, mini->center, mini->indic, mini->monitor);
			mini->indic.x += 0.5;
			mini->monitor.x += mini->ratio;
		}
		mini->indic.y += 0.5;
		mini->monitor.y += mini->ratio;
	}
}

static void	_draw_minimap(t_game *g, int center, t_vector_f indic, \
															t_vector_f monitor)
{
	if (monitor.x < 0 || monitor.y < 0)
		return ;
	_rotate(g, &indic);
	if (g->map.mini_map[(int)monitor.y][(int)monitor.x] == wall)
		my_mlx_pixel_put(&g->draw, indic.x + center, indic.y + center, H_GREY);
	else if (g->map.mini_map[(int)monitor.y][(int)monitor.x] == door)
		my_mlx_pixel_put(&g->draw, indic.x + center, indic.y + center, H_BLACK);
	else if (g->map.mini_map[(int)monitor.y][(int)monitor.x] == o_door \
		|| g->map.mini_map[(int)monitor.y][(int)monitor.x] == space \
		|| g->map.mini_map[(int)monitor.y][(int)monitor.x] == player)
		my_mlx_pixel_put(&g->draw, indic.x + center, indic.y + center, H_WHITE);
}

static void	_rotate(t_game *g, t_vector_f *indic)
{
	float	tmp;

	tmp = indic->x;
	indic->x = ((indic->x * cosf((-1) * g->player.angle_view - M_PI_2)) \
				- (indic->y * sinf((-1) * g->player.angle_view - M_PI_2)));
	indic->y = ((tmp * sinf((-1) * g->player.angle_view - M_PI_2)) \
				+ (indic->y * cosf((-1) * g->player.angle_view - M_PI_2)));
}
