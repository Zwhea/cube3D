#include "cub3D_thea.h"
#include "cub3D_arthur.h"

float	get_angle_degree(t_game *g)
{
	float	scalar;

	scalar = g->player.view.x;
	if (g->player.view.y > 0)
		return ((acos(scalar) * 3));
	return (acos(scalar));
}

void	show_fov(t_game *g)
{
	ray_minimap(g, g->player.angle_view);
}