/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   characters.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:11:56 by wangthea          #+#    #+#             */
/*   Updated: 2023/08/03 14:13:21 by twang            ###   ########.fr       */
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
int	ft_isempty(char *s);
int	ft_isfromcharset(char c, char *base);
int	ft_isprint(int c);
int	ft_iswhitespace(char c);

#endif