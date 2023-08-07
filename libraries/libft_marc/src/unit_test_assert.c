/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test_assert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:51:28 by mmosca            #+#    #+#             */
/*   Updated: 2023/08/02 15:52:34 by mmosca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

bool
	ut_assert(char *file, uint32_t line, char *expr, bool pass)
{
	g_ut.current_expression = expr;
	g_ut.current_file = file;
	g_ut.current_line = line;
	g_ut.current_test_failed = !pass;
	return (pass);
}
