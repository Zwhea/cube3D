#include "cub3D_thea.h"
// #include "cub3D_arthur.h"

int	main(int ac, char **av)
{
	t_game	g;

	ft_bzero((void *)&g, sizeof(t_game));
	if (ac <= 1)
		error_switchman(&g, no_args);
	else
	{
		if (parsing(&g, ac, av))
			return (close_n_free(&g, true));
	}
	return (0);
}
