/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_execution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 11:15:02 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/22 11:15:02 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_defs.h"
#include "grammar_interface.h"
#include "sym_interface.h"
#include "prods_interface.h"
#include <unistd.h>

static t_bool		one_symbol_transition(
		t_lst **parse_stack,
		void const **token,
		size_t token_id)
{
	void const		*sym;
	t_prod const	*derivation;

	sym = f_lstpop(parse_stack);
	if (is_terminal(sym))
	{
		if (get_token_id(sym) == token_id)
			*token = NULL;
		else
			return (FALSE);
	}
	else
	{
		derivation = get_prod_for_token(sym, token_id);
		if (!(derivation != NULL
					&& add_prod_to_stack(derivation, parse_stack)))
			return (FALSE);
	}
	return (TRUE);
}

void		*execute_construct(
		t_parser const *parser,
		char const *construct,
		void *input,
		void *(get_token)(void *input))
{
	void const	*symbol;
	void const	*token;
	t_lst		*parse_stack;

	parse_stack = NULL;
	token = NULL;
	symbol = find_sym_by_name(parser->grammar, construct);
	if (symbol != NULL
			&& NULL != f_lstpush(END_OF_INPUT_SYMBOL, &parse_stack)
			&& NULL != f_lstpush(symbol, &parse_stack))
	{
		while (parse_stack != NULL)
		{
			if (token == NULL)
				token = get_token(input);
			if (!one_symbol_transition(&parse_stack,
						&token,
						parser->get_token_id(token)))
			{
				ft_dprintf(STDERR_FILENO, "Syntax error\n");
				f_lstdel(&parse_stack, no_destroy);
				return (NULL);
			}
		}
	}
	return (input); // Dummy value, to be changed.
}

/*
** Debug
*/

static void	print_sym(void *sym)
{
	ft_dprintf(STDERR_FILENO, "%s\n", get_name(sym));
}

void	print_token(void const *token, t_parser const *parser)
{
	ft_dprintf(STDERR_FILENO, "%zu\n", parser->get_token_id(token));
}
void	print_stack(t_lst *stack)
{
	f_lstiter(stack, print_sym);
}

