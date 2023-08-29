#include "cub3D_thea.h"
#include "cub3D_arthur.h"

void	ray_minimap(t_game *g, float angle)
{
	float	plane_x;
	float	plane_y;
	float	throw_x;
	float	throw_y;

	plane_x = 165.0;
	plane_y = 30.0;
	printf("angle:%f\n", angle);
	while (plane_y <= 165)
	{
		throw_x = plane_x * cos(M_PI / 6) - plane_y * sin(M_PI / 6);
		throw_y = plane_x * sin(M_PI / 6) + plane_y * cos(M_PI / 6);
		printf("plane_y=%f : x'=%f y'=%f\n",plane_y, throw_x, throw_y);
		if (throw_x >= 0 && throw_y >= 0)
			if (plane_y <= 40)
				my_mlx_pixel_put(&g->draw, (int)throw_x, (int)throw_y, H_RED);
			else
				my_mlx_pixel_put(&g->draw, (int)throw_x, (int)throw_y, H_GREEN);
		plane_y++;
	}
}