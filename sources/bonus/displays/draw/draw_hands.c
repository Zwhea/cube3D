#include "cub3D_thea.h"
#include "cub3D_arthur.h"

void	draw_hands(t_game *g)
{
	int				x_text;
	int				y_text;
	unsigned int	color;

	x_text = 0;
	while (x_text < g->animations.player[0].width)
	{
		y_text = 0;
		while (y_text < g->animations.player[0].width)
		{
			color = my_mlx_pixel_get(&g->animations.player[0], \
				x_text, y_text);
			if (color != H_GREEN)
				my_mlx_pixel_put(&g->draw, 895 + y_text, 1015 + x_text, color);
			y_text++;
		}
		x_text++;
	}
}