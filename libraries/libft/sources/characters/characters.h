/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   characters.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:11:56 by wangthea          #+#    #+#             */
/*   Updated: 2023/07/12 14:10:42 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTERS_H
# define CHARACTERS_H

/*---- includes --------------------------------------------------------------*/

# include "libft.h"

/*---- prototypes ------------------------------------------------------------*/

int	ft_isalnum(int c);
int	ft_isalpha(int c);
int	ft_isascii(int c);
int	ft_isdigit(int c);
int	ft_isprint(int c);
int	is_from_charset(int c, char *base);

#endif