/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_parsing_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 10:39:13 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/22 10:39:13 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar_interface.h"

static char const	*g_tokens[] = {"C", "D", "E", "F", "A", "B", NULL};
static char const	*g_parse_row_check[][ARRAY_LENGTH(g_tokens)] = {
	{"SYM_2", NULL, "SYM_2", NULL, "SYM_3", NULL, "SYM_2"},
	{"C D", NULL, "E F", NULL, NULL, NULL, ""},
	{NULL, NULL, NULL, NULL, "A B", NULL, NULL}
};

static char const	g_grammar[] =
"SYM_1: SYM_3 | SYM_2;"
"SYM_2: C D | E F|;"
"SYM_3: A B";

t_bool	test_parse_table(t_grammar const *gram)
{
}

int	main(void)
{
	t_grammar	*gram;
	t_bool		result;

	gram = parse_grammar_string(g_grammar);
	result = gram != NULL
		&& compute_first_grammar(gram)
		&& compute_follow_grammar(gram)
		&& compute_parsing_table(gram, g_tokens)
		&& test_parse_table(gram);
	destroy_grammar(&gram);
	RET_TEST(result);
}
