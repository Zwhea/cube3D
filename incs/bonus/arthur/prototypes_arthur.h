/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes_arthur.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:25:03 by twang             #+#    #+#             */
/*   Updated: 2023/10/09 17:12:37 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_ARTHUR_H
# define PROTOTYPES_ARTHUR_H

/*---- includes --------------------------------------------------------------*/

# include "structures_arthur.h"

// corner.c
void			down_left_corner(t_game *g);
void			down_right_corner(t_game *g);
void			up_right_corner(t_game *g);
void			up_left_corner(t_game *g);

// show_fov.c
float			get_angle_degree(t_game *g);
void			show_fov(t_game *g);

// raycasting.c
void			ray_minimap(t_game *g, t_minimap *mini);

// mlx_pixel_get.c
unsigned int	my_mlx_pix_get(t_draw *draw, int x, int y);

void			draw_crosshair(t_game *g);

// raycasting.c
void			raycasting(t_game *g, double angle);

#endif