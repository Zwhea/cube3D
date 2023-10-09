#include "cub3D_thea.h"
#include "cub3D_arthur.h"

void	draw_crosshair(t_game *g)
{
	int	i;

	i = 529;
	while (++i <= 550)
		my_mlx_pixel_put(&g->draw, 960, i, H_WHITE);
	i = 529;
	while (++i <= 550)
		my_mlx_pixel_put(&g->draw, 959, i, H_WHITE);
	i = 529;
	while (++i <= 550)
		my_mlx_pixel_put(&g->draw, 961, i, H_WHITE);
	i = 949;
	while (++i <= 970)
		my_mlx_pixel_put(&g->draw, i, 540, H_WHITE);
	i = 949;
	while (++i <= 970)
		my_mlx_pixel_put(&g->draw, i, 541, H_WHITE);
	i = 949;
	while (++i <= 970)
		my_mlx_pixel_put(&g->draw, i, 539, H_WHITE);
}
