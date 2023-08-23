#include "cub3D_thea.h"

void	map_render(t_game *g)
{
	g->draw.img = mlx_new_image(g->mlx, WINDOW_X, WINDOW_Y);
	g->draw.addr = mlx_get_data_addr(g->draw.img, &g->draw.bits_per_pixel, \
										&g->draw.line_length, &g->draw.endian);
	// fill_background(g, WINDOW_X, WINDOW_Y, H_BLACK);
	draw_frame(g, MINI_MAP_X, MINI_MAP_Y, H_RED);
	// init_map(g, g->player.pos.x, g->player.pos.y);
	mlx_put_image_to_window(g->mlx, g->window, g->draw.img, 0, 0);
	mlx_destroy_image(g->mlx, g->draw.img);
}