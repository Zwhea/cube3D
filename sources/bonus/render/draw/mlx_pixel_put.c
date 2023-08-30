/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 16:41:16 by twang             #+#    #+#             */
/*   Updated: 2023/08/30 17:15:58 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_thea.h"

void	my_mlx_pixel_put(t_draw *data, int x, int y, int color)
{
	((int *)data->addr)[y * (data->line_length >> 2) + x] = color;
}
