/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_minimap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:50:18 by twang             #+#    #+#             */
/*   Updated: 2023/10/20 15:39:39 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*---- prototypes ------------------------------------------------------------*/

static unsigned int	_get_fov_shade(int fader);

/*----------------------------------------------------------------------------*/

float	get_angle_degree(t_game *g)
{
	float	scalar;

	scalar = g->player.view.x;
	if (g->player.view.y > 0)
		return ((acos(scalar) * 3));
	return (acos(scalar));
}

void	ray_minimap(t_game *g, t_minimap *mini)
{
	mini->degree = M_PI / 6 - M_PI_2;
	while (mini->degree >= (-1) * M_PI / 6 - M_PI_2)
	{
		mini->plane_y = 0;
		mini->fader = 0;
		while (mini->plane_y <= 165)
		{
			mini->throw_x = TILE * 7 + mini->plane_y * cos(mini->degree);
			mini->throw_y = TILE * 7 + mini->plane_y * sin(mini->degree);
			if (my_mlx_pix_get(&g->draw, mini->throw_x, mini->throw_y) \
					== H_BLACK || \
				my_mlx_pix_get(&g->draw, mini->throw_x, mini->throw_y) \
					== H_GREY)
				break ;
			if (mini->throw_x >= 0 && mini->throw_y >= 0)
			{
				mini->color = _get_fov_shade(mini->fader);
				my_mlx_pixel_put(&g->draw, (int)mini->throw_x, \
											(int)mini->throw_y, mini->color);
			}
			mini->fader++;
			mini->plane_y++;
		}
		mini->degree = mini->degree - M_PI / 768;
	}
}

static unsigned int	_get_fov_shade(int fader)
{
	int	r;
	int	g;
	int	b;

	r = ((H_GREEN >> 16) & 0xff) + 4 * fader;
	g = (H_GREEN >> 8) & 0xff;
	b = (H_GREEN & 0xff) + 4 * fader;
	if (r > 255)
		r = 255;
	if (b > 255)
		b = 255;
	return (r << 16 | g << 8 | b);
}
