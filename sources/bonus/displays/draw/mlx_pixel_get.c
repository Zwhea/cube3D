/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:12:09 by twang             #+#    #+#             */
/*   Updated: 2023/08/30 17:15:03 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"
#include "cub3D_arthur.h"

unsigned int	my_mlx_pixel_get(t_draw *draw, int x, int y)
{
	char	*dst;

	printf("x: %d\ty: %d\n", draw->line_length, draw->bits_per_pixel);
	dst = draw->addr + (y * draw->line_length + x * \
												(draw->bits_per_pixel / 8));
	printf("%s\n", dst);
	return (*(unsigned int *)dst);
}
