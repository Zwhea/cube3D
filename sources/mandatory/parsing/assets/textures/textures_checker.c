#include "cub3D.h"

void	textures_checker(t_game *g)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (i < 3 && !(g->textures.walls[i].img))
			error_switchman(g, wrong_texture);
		i++;
	}
}