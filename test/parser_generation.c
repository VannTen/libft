/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_generation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 14:11:11 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/18 14:11:11 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_interface.h"
#include "libft.h"
#include <stdlib.h>
# define INTEGER 0
# define LEFT_PAR 1
# define RIGHT_PAR 2
# define END_OF_INPUT 3

static char const	grammar[] =
"EXPR: EXPR PLUS TERM | TERM;"
"TERM: TERM MULT FACTOR | FACTOR;"
"FACTOR: INTEGER | LEFT_PAR EXPR RIGHT_PAR;";

typedef struct	s_token t_token;

struct s_token
{
	size_t	type;
	char	*start;
};

void	*create_expr(__attribute__((unused))void *no_val)
{
	int	*expr;

	expr = malloc(sizeof(*expr));
	if (expr != NULL)
		*expr = 0;
	return (expr);
}

void	give_expr(void *v_expr, void *to_give)
{
	int *expr;
	int	*term;

	expr = v_expr;
	term = to_give;
	*expr = *expr + *term;
	free(term);
}

void	*create_term(__attribute__((unused))void *no_val)
{
	int	*term;

	term = malloc(sizeof(*term));
	if (term != NULL)
		*term = 0;
	return (term);
}

void	give_term(void *v_term, void *to_give)
{
	int	*term;
	int	*factor;

	term = v_term;
	factor = to_give;
	*term = *term * *factor;
	free(factor);
}

void	*create_factor(__attribute__((unused))void *no_val)
{
	int	*factor;

	factor = malloc(sizeof(*factor));
	if (factor != NULL)
		*factor = 0;
	return (factor);
}

void	give_factor(void *v_factor, void *to_give)
{
	int	*factor;
	int	*expr_or_integer;

	factor = v_factor;
	expr_or_integer = to_give;
	*factor = *expr_or_integer;
	free(expr_or_integer);
}

void	*create_integer(void *v_integer)
{
	int	*integer;
	t_token	*integer_tok;

	integer_tok = v_integer;
	integer = malloc(sizeof(*integer));
	if (integer != NULL)
		*integer = ft_atoi(integer_tok->start);
	return (integer);
}

void	destroy_token(t_token **token)
{
	t_token	*to_destroy;

	to_destroy = *token;
	if (to_destroy != NULL)
	{
		to_destroy->type = 0;
		to_destroy->start = NULL;
		free(to_destroy);
		*token = NULL;
	}
}

void	*get_token(void	*input)
{
	char	**str;
	t_token	*new_token;

	str = input;
	new_token = malloc(sizeof(*new_token));
	if (new_token != NULL)
	{
		while (**str == ' ')
			(*str)++;
		new_token->start = *str;
		while (ft_isdigit(**str))
			(*str)++;
		if (*str != new_token->start)
			new_token->type = INTEGER;
		else if ((**str) == '(')
			new_token->type = LEFT_PAR;
		else if ((**str) == ')')
			new_token->type = RIGHT_PAR;
		else if ((**str) == '\0')
			new_token->type = END_OF_INPUT;
		else
			destroy_token(&new_token);
	}
	return (new_token);
}

size_t	get_token_index(void const *v_token)
{
	t_token	const *token;

	token = v_token;
	return (token->type);
}

int	main(void)
{
	t_parser			*parser;
	char const			*tokens_name[] = {
		"INTEGER",
		"PLUS",
		"MULT",
		NULL
	};
	t_associate	const	sym[] = {
		{.name = "EXPR", .create = create_expr, .give = give_expr},
		{.name = "TERM", .create = create_term, .give = give_term},
		{.name = "FACTOR", .create = create_factor, .give = give_factor},
		{.name = "INTEGER", .create = create_integer, .give = NULL},
		{.name = NULL, .create = NULL, .give = NULL},
	};
	int				*expr_result;
	char			input[] = "1 + 2 * 3 * (4 + 5)";

	expr_result = NULL;
	parser = generate_parser(
			grammar, tokens_name, sym, get_token_index);
	expr_result = execute_construct(parser, "EXPR", &input, get_token);
	ft_printf("%d\n", *expr_result);
}
