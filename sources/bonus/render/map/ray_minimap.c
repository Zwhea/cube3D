#include "cub3D_thea.h"
#include "cub3D_arthur.h"

void	ray_minimap(t_game *g, float angle)
{
	float	plane_y;
	float	throw_x;
	float	throw_y;
	float	degree;

	printf("%f\n", angle);
	degree = angle + M_PI / 6;
	while (degree >= angle - M_PI / 6)
	{
		plane_y = 0;
		while (plane_y <= 165)
		{
			throw_x = 165 + plane_y * cos(degree);
			throw_y = 165 + plane_y * sin(degree);
			if (my_mlx_pixel_get(g, throw_x, throw_y) == H_GREY ||
				my_mlx_pixel_get(g, throw_x, throw_y) == H_BLACK)
				break ;
			if (throw_x >= 0 && throw_y >= 0)
				my_mlx_pixel_put(&g->draw, (int)throw_x, (int)throw_y, H_GREEN);
			plane_y++;
		}
		degree = degree - M_PI / 768;
	}
}