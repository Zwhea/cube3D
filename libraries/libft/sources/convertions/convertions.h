/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:12:43 by wangthea          #+#    #+#             */
/*   Updated: 2023/07/29 23:52:57 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTIONS_H
# define CONVERTIONS_H

/*---- includes --------------------------------------------------------------*/

# include "libft.h"

/*---- prototypes ------------------------------------------------------------*/

int 	ft_atoi_base(const char *str, int str_base);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
char	*search_and_replace(char *string, char search, char replace);
int		ft_tolower(int c);
int		ft_toupper(int c);

#endif