/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arith_expr_test_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 13:15:05 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/22 13:15:05 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_interface.h"
#include <stdlib.h>

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