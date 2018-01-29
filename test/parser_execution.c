/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_execution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 14:11:11 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/18 14:11:11 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_interface.h"
#include "test_interface.h"
#include "libft.h"
#include <unistd.h>

static char const	grammar[] =
"EXPR: EXPR PLUS TERM | TERM;"
"TERM: TERM MULT FACTOR | FACTOR;"
"FACTOR: INTEGER | LEFT_PAR EXPR RIGHT_PAR;";

static t_bool	test(t_parser const *parser)
{
	size_t	index;
	char const *const	expression[] = {
		"1 + 2",
		"1*3+4",
		"2 * 2 * 2",
		"43 + 12 * (75 + (1 + 4 * 3))",
		"(0 * 1) + 2",
	};
	char const			*input;
	int	const			cmp[] = {
		1 + 2,
		1 * 3 + 4,
		2 * 2 *2,
		43 + 12 * (75 + (1 + 4 * 3)),
		(0 * 1) + 2
	};
	int					*result;

	index = 0;
	while (index < ARRAY_LENGTH(expression))
	{
		input = expression[index];
		result = execute_construct(parser, "EXPR", &input, get_token);
		if (*result != cmp[index])
		{
			ft_dprintf(STDERR_FILENO,
					"Expression : %s. Result : %d. Expected : %d.\n",
					expression[index], *result, cmp[index]);
			break ;
		}
		free(result);
		index++;
	}
	return (index == ARRAY_LENGTH(expression));
}

int				main(void)
{
	t_parser			*parser;
	char const			*tokens_name[] = {
		"INTEGER",
		"PLUS",
		"MULT",
		"LEFT_PAR",
		"RIGHT_PAR",
		NULL
	};
	t_exec	const		sym[] = {
		{.name = "EXPR", .create = create_expr, .give = give_expr},
		{.name = "TERM", .create = create_term, .give = give_term},
		{.name = "FACTOR", .create = create_factor, .give = give_factor},
		{.name = "INTEGER", .create = create_integer, .give = NULL},
		{.name = NULL, .create = NULL, .give = NULL},
	};

	parser = generate_parser(
			grammar, tokens_name, sym, get_token_index);
	RET_TEST(test(parser));
}
