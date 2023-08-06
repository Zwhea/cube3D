/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes_thea.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:25:03 by twang             #+#    #+#             */
/*   Updated: 2023/08/05 18:10:08 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_THEA_H
# define PROTOTYPES_THEA_H

/*---- includes --------------------------------------------------------------*/

# include "structures_thea.h"

/*----------------------------------------------------------------------------*/

/*---- init/ -----------------------------------------------------------------*/
/*--------------- mlx/ -------------------------------------------------------*/

void	init_mlx(t_game *g);

/*--------------- struct/ ----------------------------------------------------*/

void	init_struct(t_game *g);
void	set_vector(t_vector *vector, int x, int y);

/*---- parsing/ --------------------------------------------------------------*/

int		parsing(t_game *g, int ac, char **av);

/*--------------- assets/ ----------------------------------------------------*/

void	asset_switchman(t_game *g, char *line);

/*---------------------- colors/ ---------------------------------------------*/
/*------------------------- get_colors.c -------------------------------------*/

void	handle_ceiling_color(t_game *g, char *line);
void	handle_floor_color(t_game *g, char *line);
void	handle_no_asset(t_game *g, char *line);

/*---------------------- textures/ -------------------------------------------*/
/*------------------------- get_textures.c -----------------------------------*/

void	handle_north_texture(t_game *g, char *line);
void	handle_south_texture(t_game *g, char *line);
void	handle_west_texture(t_game *g, char *line);
void	handle_east_texture(t_game *g, char *line);

/*------------------------- textures_checker.c -------------------------------*/

void	textures_checker(t_game *g);

/*--------------- errors/ ----------------------------------------------------*/

void	error_switchman(t_game *g, t_keyerror error_key);

/*---------------------- inventory/ ------------------------------------------*/
/*------------------------- argument.c ---------------------------------------*/

void	_no_arg(t_game *g);
void	_much_arg(t_game *g);

/*------------------------- asset.c ------------------------------------------*/

void	_wrong_asset(t_game *g);

/*------------------------- file.c -------------------------------------------*/

void	_wrong_file(t_game *g);

/*------------------------- map.c --------------------------------------------*/

void	_wrong_map(t_game *g);

/*--------------- map/ -------------------------------------------------------*/
/*------------------------- get_map.c ----------------------------------------*/

void	get_map(t_game *g, int fd, int start_map);

/*------------------------- map_checker.c ------------------------------------*/

void	map_checker(t_game *g);

/*------------------------- utils.c ------------------------------------------*/

bool	is_map(char *s);
size_t	set_map_height(t_game *g, int fd);

/*--------------- utils/ -----------------------------------------------------*/
/*------------------------- checkers.c ---------------------------------------*/

void	is_this_first_mistake(t_game *g, bool is_warning);

/*------------------------- clean.c ------------------------------------------*/

int		close_n_free(t_game *g, bool is_error);
void	clean_textures(t_game *g);
void	clean_map(t_game *g);
int		clean(t_game *g);

/*------------------------- prints.c -----------------------------------------*/

void	ft_error(t_game *g, bool is_warn, bool how_to, char *msg);

#endif