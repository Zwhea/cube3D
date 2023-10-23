#include "cub3D.h"

void	_print_henri1(t_game *g)
{
	t_vector	pos;
	int			dual;
	// static int	pos
	mlx_set_font(g->mlx, g->window, "-*-*-*-*-*-*-*-*-*-*-*-90-*-*");
	// mlx_string_put(g->mlx, g->window, WINDOW_X / 2 - 60 - 100 * (sin(g->player.posf.x)), WINDOW_Y / 2 - 40 - 100 * (cos(g->player.posf.y)),
	// 	H_GREEN, "<3 MERCI HENRI GEFFROY <3");	
	// mlx_string_put(g->mlx, g->window, WINDOW_X / 2 - 60 + 100 * (cos(g->player.posf.x)), WINDOW_Y / 2 - 40 + 100 * (sin(g->player.posf.y)),
	// 	H_PINK, "GO GO GO GO GO GO GO GO GO");
	// mlx_string_put(g->mlx, g->window, WINDOW_X / 2 - 60 - 100 * (sin(g->player.posf.x)), WINDOW_Y / 2 - 40 - 100 * (cos(g->player.posf.y)),
	// 	H_GREEN, "<3 MERCI HENRI GEFFROY <3");	
	// mlx_string_put(g->mlx, g->window, WINDOW_X / 2 - 60 + 100 * (cos(g->player.posf.x)), WINDOW_Y / 2 - 40 + 100 * (sin(g->player.posf.y)),
	// 	H_PINK, "GO GO GO GO GO GO GO GO GO");
	// mlx_string_put(g->mlx, g->window, WINDOW_X / 2 + 300 - 100 * (sin(g->player.posf.x)), WINDOW_Y / 2 - 40 - 100 * (cos(g->player.posf.y)),
	// 	H_GREEN, "<3 MERCI HENRI GEFFROY <3");	
	// mlx_string_put(g->mlx, g->window, WINDOW_X / 2 + 300 + 100 * (cos(g->player.posf.x)), WINDOW_Y / 2 - 40 + 100 * (sin(g->player.posf.y)),
	// 	H_PINK, "GO GO GO GO GO GO GO GO GO");
	// mlx_string_put(g->mlx, g->window, WINDOW_X / 2 - 300 - 100 * (sin(g->player.posf.x)), WINDOW_Y / 2 - 40 - 100 * (cos(g->player.posf.y)),
	// 	H_GREEN, "<3 MERCI HENRI GEFFROY <3");	
	// mlx_string_put(g->mlx, g->window, WINDOW_X / 2 - 300 + 100 * (cos(g->player.posf.x)), WINDOW_Y / 2 - 40 + 100 * (sin(g->player.posf.y)),
	// 	H_PINK, "GO GO GO GO GO GO GO GO GO");
	pos.x = 100;
	dual = 0;
	while (pos.x < 1820)
	{
		pos.y = 0;
		while (pos.y < 1080)
		{
			pos.y += 100;
			if (dual == 0)
			{
				mlx_string_put(g->mlx, g->window, pos.x, pos.y,
					H_ORANGE, "<3 MERCI HENRI GEFFROY <3");
				dual = 1;
			}
			else if (dual == 1)
			{
				mlx_string_put(g->mlx, g->window, pos.x, pos.y,
					H_PINK, " GO GO GO GO GO GO GO GO");
				dual = 0;
			}
		}
		pos.x += 300;
	}
}

void	thx_henri(t_game *g)
{
	if (g->switches.h_henri == 1)
		_print_henri1(g);
}

void	switch_henri(t_game *g)
{
	if (g->switches.h_henri == 1)
		g->switches.h_henri = 0;
	else if (g->switches.h_henri == 0)
		g->switches.h_henri = 1;
}