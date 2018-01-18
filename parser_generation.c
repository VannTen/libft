/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_generation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:00:13 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/18 18:00:13 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_defs.h"

t_parser	*generate_parser(
		char const *grammar,
		char const **tokens_names,
		t_associate const *rules,
		size_t (*get_token_id)(void const *token))
{
	t_parser	*new_parser;

	new_parser = malloc(sizeof(*new_parser));
	if (new_parser != NULL)
	{
		new_parser->gram = parse_grammar_from_string(grammar);
		if (new_parser->grammar == NULL
				|| !eliminate_all_left_recursion(new_parser->grammar)
				|| !left_factor_grammar(new_parser->grammar)
				|| !compute_first_grammar(new_parser->grammar)
				|| !compute_follow_grammar(new_parser->grammar)
				|| !compute_parsing_table(new_parser->grammar, token_names))
			destroy_parser(&new_parser);
		else
		{
			new_parser->get_token_id = get_token_id;
			lookahead_token = NULL;
			parse_stack = NULL;
			associate_exec(rules, new_parser->grammar);
		}

	}
	return (new_parser);
}

void		*destroy_parser(t_parser **parser)
{
	t_parser	*to_destroy;

	to_destroy = *parser;
	if (to_destroy != NULL)
	{
		destroy_grammar(&to_destroy->grammar);
		f_lstdel(&parse_stack, no_destroy);
		*parser = NULL;
	}
}
