#include "cub3D_thea.h"
#include "cub3D_arthur.h"

float	get_angle_degree(t_game *g)
{
	float	scalar;
	float	norm;

	scalar = g->player.view.x;
	if (g->player.view.y < 0)
		return ((acos(scalar) * -1) * (180 / M_PI));
	return (acos(scalar) * (180 / M_PI));
}

void	show_fov(t_game *g)
{
	printf("angle=%f et view_x = %f : et view_y = %f\n", get_angle_degree(g), g->player.view.x, g->player.view.y);
	
}