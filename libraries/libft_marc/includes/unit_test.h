/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:40:03 by mmosca            #+#    #+#             */
/*   Updated: 2023/08/02 15:52:59 by mmosca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIT_TEST_H
# define UNIT_TEST_H

// -- Includes -----------------------------------------------------------------

# include <stdint.h>
# include <stdio.h>
# include <string.h>
# include <stdbool.h>

// -- Defines ------------------------------------------------------------------

# define UT_COLOR_CODE 0x1B
# define UT_COLOR_RED "[1;31m"
# define UT_COLOR_GREEN "[1;32m"
# define UT_COLOR_RESET "[0m"

# ifndef RUN
#  define RUN
# endif

# ifndef REPORT
#  define REPORT
# endif

# ifndef ASSERT
#  define ASSERT
# endif

# ifndef ASSERT_EQUALS
#  define ASSERT_EQUALS
# endif

# ifndef ASSERT_STRINGS_EQUALS
#  define ASSERT_STRINGS_EQUALS
# endif

// -- Typedefs -----------------------------------------------------------------

typedef struct s_unit_test	t_unit_test;

// -- Globals ------------------------------------------------------------------

t_unit_test					g_ut;

// -- Structures ---------------------------------------------------------------

struct s_unit_test
{
	uint32_t	passes;
	uint32_t	fails;
	uint32_t	current_test_failed;
	uint32_t	current_line;
	char		*current_expression;
	char		*current_file;
};

// -- Prototypes ---------------------------------------------------------------

bool
ut_assert(char *file, uint32_t line, char *expr, bool pass);

uint32_t
ut_report(void);

void
ut_run(const char *name, void (*test_function)());

#endif //UNIT_TEST_H
