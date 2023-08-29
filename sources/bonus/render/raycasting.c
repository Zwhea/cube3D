#include "cub3D_thea.h"
#include "cub3D_arthur.h"

void	ray_minimap(t_game *g, float angle)
{
	int	plane_x;
	int	plane_y;

	plane_x = 165;
	plane_y = 30;
	while (plane_y <= 165)
	{
		my_mlx_pixel_put(&g->draw, plane_x * cos(angle) - plane_y * sin(angle), plane_x * sin(angle) + plane_y * cos(angle), H_RED);
		plane_y++;
	}
}