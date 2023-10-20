/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:02:27 by twang             #+#    #+#             */
/*   Updated: 2023/10/20 14:20:04 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

/*---- error messages --------------------------------------------------------*/

# define ERROR "error: "
# define WARNING "warning: "
# define NO_ARG "program needs a map you fool !!!\n"
# define WRONG_FILE "program encounter issues with given file\n"
# define WRONG_ASSET "program encounter issues with given informations\n"
# define WRONG_TEXTURE "program encounter issues with given textures\n"
# define WRONG_TEXTURES "a bit too much textures don't you think ?\n"
# define WRONG_COLOR "program encounter issues with given colors\n"
# define WRONG_COLORS "and that's too much colors right ?\n"
# define WRONG_MAP "program encounter issues with given map\n"
# define WRONG_CHAR "you have an unwanted character in your map\n"
# define WRONG_PLAYER "you have an issue with player character in your map\n"
# define WRONG_DOOR "you have an issue with door character in your map\n"

/*---- authorized charset ----------------------------------------------------*/

# define TEXTURE_CHARSET	"NOSOWEEA "
# define TEXTURE_NORTH		"NO "
# define TEXTURE_SOUTH		"SO "
# define TEXTURE_WEST		"WE "
# define TEXTURE_EAST		"EA "
# define TEXTURE_CEILING	"CE "
# define TEXTURE_FLOOR		"FL "

# define COLOR_FLOOR		"F "
# define COLOR_CEILING		"C "
# define COLOR_CHARSET		"0123456789,"

# define MAP_CHARSET		"01NSEW- \n"
# define PLAYER_CHARSET		"NSEW"

/*---- sizes (windows, textures, images) -------------------------------------*/

# define WINDOW_X			1920
# define WINDOW_Y			1080
# define MINI_MAP_X			270
# define MINI_MAP_Y			270
# define TILE				30

/*---- colors ----------------------------------------------------------------*/

# define H_WHITE			0xffffff
# define H_BLACK			0x000000
# define H_RED				0xff0000
# define H_GREEN			0x00ff00
# define H_DARKGREEN		0x01452c
# define H_BLUE				0x0000ff
# define H_YELLOW			0xffff00
# define H_ORANGE			0xffa500
# define H_PINK				0xffc0cb
# define H_PURPLE			0x800080
# define H_GREY				0x808080

/*---- animations xpm --------------------------------------------------------*/

# define XPM_DOOR			"./assets/textures/xpm/door_closed.xpm"
# define XPM_PLAYER			"./assets/textures/xpm/hands.xpm"

#endif