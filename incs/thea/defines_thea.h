/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines_thea.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:02:27 by twang             #+#    #+#             */
/*   Updated: 2023/07/27 16:03:23 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_THEA_H
# define DEFINES_THEA_H

/*---- error messages --------------------------------------------------------*/

# define WARNING "warning: "
# define USAGE "usage: "

# define NO_ARG "\tprogram needs a map you fool !!!\n"
# define TOO_MUCH_ARG "program will only look at the first argument.\n"
# define NO_FILE "program cannot open the file, check your file name & path\n"
# define NO_EXTRACT "\tprogram cannot extract the informations from the file\n"
# define RD_FAIL "cannot read the file correctly\n"
# define NO_MAP "the map seems corrupted, check the file\n"
# define TEXTURES "the textures seems corrupted, check the textures paths\n"

/*---- authorized charset ----------------------------------------------------*/

# define TEXTURE_CHARSET "NOSOWEEA "
# define COLOR_CHARSET "FC "
# define COLOR_NM_CHARSET "0123456789, "
# define MAP_CHARSET "01NSEW "

#endif