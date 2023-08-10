#include "cub3D_thea.h"
#include "cub3D_arthur.h"

/*---- prototypes ------------------------------------------------------------*/

static int	_key_press(t_keycode key, t_game *g);

/*----------------------------------------------------------------------------*/

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
		mlx_key_hook(g.window, _key_press, &g);
		mlx_hook(g.window, 17, 1L << 17, clean, &g);
		mlx_loop(g.mlx);
		clean(&g);
	}
	return (0);
}

static int	_key_press(t_keycode key, t_game *g)
{
	if (key == esc_key)
		clean(g);
	return (0);
}

/*
- revoir gestion d'erreurs

leaks, fds, mlx leaks, clean EVERYTHING YUP.

*/