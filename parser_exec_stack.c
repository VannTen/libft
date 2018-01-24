/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_exec_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 13:37:22 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/23 13:37:22 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_construct_defs.h"
#include "libft.h"
#include <assert.h>

static t_bool				one_less_symbol(t_lst **exec_stack)
{
	t_exec_construct	*current;
	t_exec_construct	*parent;
	t_bool				result;

	current= (void*)get_lst_elem(*exec_stack, 0);
	assert(current!= NULL);
	current->remaining_symbols--;
	if (current->remaining_symbols == 0)
	{
		(void)f_lstpop(exec_stack);
		parent= (void*)get_lst_elem(*exec_stack, 0);
		result = parent->functions->give(
				parent->real, current->real);
		destroy_construct(&current);
		return (result);
	}
	else
		return (TRUE);
}

/*
** Zero length prod are tokens (consummed, so expand to 0 symbol) and empty
** productions
*/

static t_bool			zero_length_prod(void const *token_from_lexer,
		t_lst **exec_stack,
		t_exec const *functions_token)
{
	t_exec_construct	*parent;
	void				*final_token;

	if (functions_token != NULL)
	{
		final_token = functions_token->create(token_from_lexer);
		if (final_token != NULL)
		{
			parent = (void*)get_lst_elem(*exec_stack, 0);
			parent->functions->give(parent->real, final_token);
		}
		else
			return (FALSE);
	}
	return (TRUE);
}

static void		*concrete_construct(
		void const *value,
		t_lst **exec_stack,
		t_exec const *functions,
		size_t const prod_len)
{
	t_exec_construct	*current_construct;

	if (prod_len == 0)
		return (zero_length_prod(value, exec_stack, functions) ?
				(void*)get_lst_elem(*exec_stack, 0) : NULL);
	else
	{
		current_construct = create_construct(functions);
		current_construct->real =
			current_construct->functions->create(NULL);
		if (current_construct->real == NULL
				|| NULL == f_lstpush(current_construct, exec_stack))
			destroy_construct(&current_construct);
	}
	return (current_construct);
}

static t_bool			put_one_prod_in_stack(
		void const *value,
		t_lst **exec_stack,
		t_exec const *functions,
		size_t const prod_len)
{
	t_exec_construct	*current_construct;

	if (functions != NULL)
		current_construct = concrete_construct(value,
				exec_stack, functions, prod_len);
	else
		current_construct = (void*)get_lst_elem(*exec_stack, 0);
	if (current_construct != NULL)
	{
		current_construct->remaining_symbols += prod_len;
		return (one_less_symbol(exec_stack));
	}
	else
		return (FALSE);
}

t_bool		put_token_in_stack(
		void const *value,
		t_lst **exec_stack,
		t_exec const *functions)
{
	return (put_one_prod_in_stack(value, exec_stack, functions, 0));
}

t_bool		put_sym_in_stack(
		t_lst **exec_stack,
		t_exec const *functions,
		size_t const prod_len)
{
	return (put_one_prod_in_stack(NULL, exec_stack, functions, prod_len));
}
