#include "cub3D_thea.h"
#include "cub3D_arthur.h"

int	main(int ac, char **av)
{
	t_game	g;

	init_struct(&g);
	if (ac <= 1)
		error_switchman(&g, no_args);
	else
	{
		if (parsing(&g, ac, av) != 0)
			return (close_n_free(&g, true));
		map_render(&g);
		init_mlx_functions(&g);
		clean(&g);
	}
	return (0);
}
