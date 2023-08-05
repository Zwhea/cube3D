#include "cub3D_thea.h"
// #include "cub3D_arthur.h"

int	main(int ac, char **av)
{
	t_game	g;

	init_struct(&g);
	if (ac <= 1)
		error_switchman(&g, no_args);
	else
	{
		init_mlx(&g);
		if (parsing(&g, ac, av))
			return (close_n_free(&g, true));
		mlx_loop(g.mlx);
		clean(&g);
	}
	return (0);
}
