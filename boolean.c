/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boolean.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 15:10:16 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/26 16:42:38 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bool_defs.h"
#include "string_interface.h"
#include <stddef.h>

static t_char_tester	select_test(const char *test)
{
	const char			*test_notation[] = {
		"==", "!=", "<", ">", "<=", ">=", NULL};
	const t_char_tester	tests[] = {
		equal_char, diff_char,
		lower_char, greater_char, lower_equal_char, greater_equal_char};
	size_t				index;

	index = 0;
	while (test_notation[index] != NULL)
	{
		if (ft_strncmp(test_notation[index], test, 2) == 0)
			return (tests[index]);
		index++;
	}
	return (NULL);
}

t_bool					string_test(char to_test, const char *to_test_against,
		const char *test_str)
{
	t_char_tester	test;
	size_t			index;

	test = select_test(test_str);
	if (test != NULL)
	{
		index = 0;
		if (to_test_against[0] == '\0')
		{
			if (test(to_test, '\0'))
				return (TRUE);
			else
				index++;
		}
		while (to_test_against[index] != '\0')
		{
			if (test(to_test_against[index], to_test))
				return (TRUE);
			index++;
		}
		return (FALSE);
	}
	return (TRUE);
}
