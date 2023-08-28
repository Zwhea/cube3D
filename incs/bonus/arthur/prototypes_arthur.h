/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes_arthur.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:25:03 by twang             #+#    #+#             */
/*   Updated: 2023/07/20 10:21:49 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_ARTHUR_H
# define PROTOTYPES_ARTHUR_H

/*---- includes --------------------------------------------------------------*/

# include "structures_arthur.h"

/*----------------------------------------------------------------------------*/
void	down_left_corner(t_game *g);
void	down_right_corner(t_game *g);
void	up_right_corner(t_game *g);
void	up_left_corner(t_game *g);

#endif