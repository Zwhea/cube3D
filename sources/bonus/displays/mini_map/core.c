/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 08:46:47 by aascedu           #+#    #+#             */
/*   Updated: 2023/10/05 16:37:58 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"
#include "cub3D_arthur.h"

/*---- prototypes ------------------------------------------------------------*/

static void	_init_minimap(t_game *g);
static void	_draw_minimap(t_game *g, int center, t_vector_f indic, t_vector_f monitor);

/*----------------------------------------------------------------------------*/

void	minimap_display(t_game *g)
{
	_init_minimap(g);
	ray_minimap(g, g->player.angle_view);
	draw_circle(g, 155, 155, H_DARKGREEN);
}

// static void	_init_minimap(t_game *g)
// {
// 	down_left_corner(g);
// 	down_right_corner(g);
// 	up_right_corner(g);
// 	up_left_corner(g);
// }

static void	_init_minimap(t_game *g)
{
	int			center;
	int			rayon;
	float		ratio;
	t_vector_f	indic;
	t_vector_f	monitor;

	center = TILE * 7;
	rayon = TILE * 6;
	set_vector_f(&indic, -rayon, -rayon);
	set_vector_f(&monitor, g->player.posf.x - 4.5, g->player.posf.y - 4.5);
	ratio = 1.f / TILE;
	while (indic.x < rayon)
	{
		indic.y = -rayon;
		monitor.y = g->player.posf.y - 4.5;
		while (indic.y < rayon)
		{
			_draw_minimap(g, center, indic, monitor);
			indic.y++;
			monitor.y += ratio;
		}
		indic.x++;
		monitor.x += ratio;
	}
}

static void	_draw_minimap(t_game *g, int center, t_vector_f indic, t_vector_f monitor)
{
	if (monitor.x < 0 || monitor.y < 0)
		return ;
	printf("%f\t%f\n", monitor.x, monitor.y);
	if (g->map.map[(int)monitor.y][(int)monitor.x] == wall)
		my_mlx_pixel_put(&g->draw, indic.x + center, indic.y + center, H_GREY);
	else if (g->map.map[(int)monitor.y][(int)monitor.x] == space \
		|| g->map.map[(int)monitor.y][(int)monitor.x] == north \
		|| g->map.map[(int)monitor.y][(int)monitor.x] == east \
		|| g->map.map[(int)monitor.y][(int)monitor.x] == west \
		|| g->map.map[(int)monitor.y][(int)monitor.x] == south)
		my_mlx_pixel_put(&g->draw, indic.x + center, indic.y + center, H_WHITE);
	else if (g->map.map[(int)monitor.y][(int)monitor.x] == door)
		my_mlx_pixel_put(&g->draw, indic.x + center, indic.y + center, H_BLACK);
}
