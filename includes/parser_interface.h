/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_interface.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 15:12:51 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/18 15:12:51 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_INTERFACE_H
# define PARSER_INTERFACE_H
# include <stddef.h>

typedef struct s_parser	t_parser;

typedef	void *(*t_create_construct)(void *lex_value);
typedef	void (*t_give_construct)(void *construct, void *sub_construct);

typedef struct s_associate	t_associate;

/*
** This is the interface with the execution side :
**
** - 'create' will be called when a symbol begin to be parsed
** with NULL if 'lex_value' is a non-terminal,
** with the return of 'get_token(input)' if it is a token.
**
** - 'give' will be called when a construct has been entirely parsed (and so,
** given all its sub_constructs.
** Its first argument will be the current construct parsed, its second the one
** just finished.
**
** A construct will be 'finished' when all of its subconstructs are, if it is a
** non-terminal, or when it is created by its own 'create', if it is a terminal.
** (Terminals symbols do not need a give member, and create is expected to
** translate the lexer representation into whatever form the execution needs).
*/

struct	s_associate
{
	char const			*name;
	t_create_construct	create;
	t_give_construct	give;
};

/*
** Parser generation
*/

t_parser	*generate_parser(
		char const *grammar,
		char const **tokens_names,
		t_associate const *rules,
		size_t (*get_token_id)(void const *token));
void		destroy_parser(t_parser **parser);

/*
** Parser execution
*/

void		*execute_construct(
		t_parser *parser,
		char const *construct,
		void *input,
		void *(get_token)(void *input));

#endif
