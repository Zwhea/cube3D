/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes_thea.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:25:03 by twang             #+#    #+#             */
/*   Updated: 2023/08/02 18:37:07 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_THEA_H
# define PROTOTYPES_THEA_H

/*---- includes --------------------------------------------------------------*/

# include "structures_thea.h"

/*----------------------------------------------------------------------------*/

/*---- parsing ---------------------------------------------------------------*/

int		parsing(t_game *g, int ac, char **av);

/*--------------- assets -----------------------------------------------------*/
/*------------------------- check_assets.c -----------------------------------*/

int		check_textures(t_game *g, char *line);
int		check_colors(t_game *g, char *line);

/*------------------------- get_assets.c -------------------------------------*/

void	which_asset(t_game *g, char *line);

/*------------------------- get_colors.c -------------------------------------*/

void	get_ceiling_color(t_game *g, char *line);
void	get_floor_color(t_game *g, char *line);
void	error_asset(t_game *g, char *line);

/*------------------------- get_textures.c -----------------------------------*/

void	get_north_texture(t_game *g, char *line);
void	get_south_texture(t_game *g, char *line);
void	get_west_texture(t_game *g, char *line);
void	get_east_texture(t_game *g, char *line);

/*------------------------- utils.c ------------------------------------------*/

/*--------------- errors -----------------------------------------------------*/
/*---------------------- \inventory ------------------------------------------*/
/*------------------------- argument.c ---------------------------------------*/

void	no_arg(t_game *g);
void	too_much_arg(t_game *g);

/*------------------------- asset.c ------------------------------------------*/

void	bad_asset(t_game *g);

/*------------------------- file.c -------------------------------------------*/

void	no_file(t_game *g);
void	failed_extract(t_game *g);

/*------------------------- map.c --------------------------------------------*/

/*------------------------- error_switchman.c --------------------------------*/

void	error_switchman(t_game *g, t_keyerror error_key);

/*--------------- file -------------------------------------------------------*/
/*------------------------- get_file.c ---------------------------------------*/

char	**get_file(t_game *g, char *file);

/*------------------------- utils.c ------------------------------------------*/

void	read_error(int fd);
int		get_alloc_size(const char *file);

/*--------------- map --------------------------------------------------------*/
/*------------------------- get_map.c ----------------------------------------*/

void	get_map(t_game *g, int fd, int start_map);

/*------------------------- utils.c ------------------------------------------*/

bool	is_map(char *s);

/*--------------- utils ------------------------------------------------------*/
/*------------------------- checkers.c ---------------------------------------*/

void	is_this_first_mistake(t_game *g, bool is_warning);

/*------------------------- clean.c ------------------------------------------*/

int		close_n_free(t_game *g, bool is_error);

/*------------------------- prints.c -----------------------------------------*/

void	ft_error(t_game *g, bool is_warn, bool how_to, char *msg);

#endif