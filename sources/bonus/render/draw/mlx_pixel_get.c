#include "cub3D_thea.h"
#include "cub3D_arthur.h"

unsigned int	my_mlx_pixel_get(t_game *g, int x, int y)
{
	char	*dst;

	dst = g->draw.addr + (y * g->draw.line_length + x * (g->draw.bits_per_pixel / 8));
	return (*(unsigned int*)dst);
}