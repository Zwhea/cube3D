#include "cub3D_thea.h"
#include "cub3D_arthur.h"

float	get_angle_degree(t_game *g)
{
	float	scalar;
	float	norm;

	scalar = g->player.view.x;
	if (g->player.view.y < 0)
		return ((acos(scalar) * -1));
	return (acos(scalar));
}

void	show_fov(t_game *g)
{
	float	angle;

	angle = get_angle_degree(g);
	ray_minimap(g, angle);
}