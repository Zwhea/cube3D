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
		if (parsing(&g, av))
			return (close_n_free(&g, true));
		clean(&g);
	}
	return (0);
}

/*
- revoir gestion d'erreurs

leaks, fds, mlx leaks, clean EVERYTHING YUP.
window opening no matter what

*/