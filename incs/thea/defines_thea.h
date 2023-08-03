/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines_thea.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:02:27 by twang             #+#    #+#             */
/*   Updated: 2023/08/03 16:26:23 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_THEA_H
# define DEFINES_THEA_H

/*---- error messages --------------------------------------------------------*/

# define NO_ARG "\tprogram needs a map you fool !!!\n"
# define MUCH_ARG "program will only accept the first argument.\n"

# define WRONG_FILE "program encounter issues with given file\n"
# define WRONG_ASSET "program encounter issues with given informations\n"

/*---- authorized charset ----------------------------------------------------*/

# define TEXTURE_CHARSET "NOSOWEEA "
# define TEXTURE_NORTH "NO "
# define TEXTURE_SOUTH "SO "
# define TEXTURE_WEST "WE "
# define TEXTURE_EAST "EA "

# define COLOR_CHARSET "FC "
# define COLOR_FLOOR "F "
# define COLOR_CEILING "C "
# define COLOR_NM_CHARSET "0123456789, "

# define MAP_CHARSET "01NSEW "

#endif