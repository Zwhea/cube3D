/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test_run.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:50:01 by mmosca            #+#    #+#             */
/*   Updated: 2023/08/02 15:50:48 by mmosca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

void
	ut_run(const char *name, void (*test_function)())
{
	g_ut.current_test_failed = 0;
	test_function();
	if (g_ut.current_test_failed)
	{
		dprintf(2, "failure: %s:%d: In test %s():\n\t%s\n", \
			g_ut.current_file, g_ut.current_line, name, \
			g_ut.current_expression);
		g_ut.fails++;
	}
	else
		g_ut.passes++;
}
