#include "cub3D_thea.h"
#include "cub3D_arthur.h"

int	check_w_move(t_game *g)
{
	int	init_x;
	int	init_y;
	int	dist_x;
	int	dist_y;

	dist_y = floor(g->player.posf.y + 0.30000 * sin(g->player.angle_view));
	dist_x = floor(g->player.posf.x + 0.30000 * cos(g->player.angle_view));
	init_x = floor(g->player.posf.x);
	init_y = floor(g->player.posf.y);
	if (dist_x < 0 || dist_y < 0)
		return (1);
	if (g->map.map[dist_y] && g->map.map[dist_y][dist_x] && g->map.map[dist_y][dist_x] != wall)
		return (0);
	return (1);
}

int	check_s_move(t_game *g)
{
	int	dist_x;
	int	dist_y;

	dist_x = floor(g->player.posf.x + 0.30000 * sin(g->player.angle_view));
	dist_y = floor(g->player.posf.y - 0.30000 * cos(g->player.angle_view));
	if (dist_x < 0 || dist_y < 0)
		return (1);
	if (g->map.map[dist_y] && g->map.map[dist_y][dist_x] && g->map.map[dist_y][dist_x] != wall)
		return (0);
	return (1);
}

int	check_a_move(t_game *g)
{
	int	dist_x;
	int	dist_y;

	dist_x = floor(g->player.posf.x + 0.30000 * sin(g->player.angle_view));
	dist_y = floor(g->player.posf.y - 0.30000 * cos(g->player.angle_view));
	if (dist_x < 0 || dist_y < 0)
		return (1);
	if (g->map.map[dist_y] && g->map.map[dist_y][dist_x] && g->map.map[dist_y][dist_x] != wall)
		return (0);
	return (1);
}

int	check_d_move(t_game *g)
{
	int	dist_x;
	int	dist_y;

	dist_x = floor(g->player.posf.x - 0.30000 * sin(g->player.angle_view));
	dist_y = floor(g->player.posf.y + 0.30000 * cos(g->player.angle_view));
	if (dist_x < 0 || dist_y < 0)
		return (1);
	if (g->map.map[dist_y] && g->map.map[dist_y][dist_x] && g->map.map[dist_y][dist_x] != wall)
		return (0);
	return (1);
}