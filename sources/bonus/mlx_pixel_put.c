/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 16:41:16 by twang             #+#    #+#             */
/*   Updated: 2023/08/06 16:43:24 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	my_mlx_pixel_put(t_draw *draw, int x, int y, int color)
{
	char	*dst;

	dst = draw->addr + (y * draw->line_length + x * (draw->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}