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

#include "cub3D.h"

unsigned int	my_mlx_pix_get(t_draw *draw, int x, int y)
{
	char	*dst;

	dst = draw->addr + (y * draw->line_length + x * \
												(draw->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}
