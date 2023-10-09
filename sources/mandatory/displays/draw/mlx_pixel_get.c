/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:12:09 by twang             #+#    #+#             */
/*   Updated: 2023/10/09 17:12:37 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"
#include "cub3D_arthur.h"

unsigned int	my_mlx_pix_get(t_game *g, int x, int y)
{
	char	*dst;

	dst = g->draw.addr + (y * g->draw.line_length + x * \
												(g->draw.bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}
