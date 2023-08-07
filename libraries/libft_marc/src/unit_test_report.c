/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test_report.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:45:12 by mmosca            #+#    #+#             */
/*   Updated: 2023/08/02 15:49:20 by mmosca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

uint32_t
	ut_report(void)
{
	if (g_ut.fails)
	{
		dprintf(2, "%c%sFAILED%c%s [%s] (passed:%d, failed:%d, total:%d)\n", \
			UT_COLOR_CODE, UT_COLOR_RED, UT_COLOR_CODE, UT_COLOR_RESET, \
			g_ut.current_file, g_ut.passes, g_ut.fails, \
			g_ut.passes + g_ut.fails);
		return (1);
	}
	else
	{
		dprintf(2, "%c%sPASSED%c%s [%s] (total:%d)\n", \
			UT_COLOR_CODE, UT_COLOR_GREEN, UT_COLOR_CODE, UT_COLOR_RESET, \
			g_ut.current_file, g_ut.passes);
		return (0);
	}
}
