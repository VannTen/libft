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

t_bool			give_to_parent(t_exec_construct **child,
		t_exec_construct const *parent)
{
	t_bool	result;

	assert(child != NULL && *child != NULL);
	result = parent->functions->give(parent->real, (*child)->real);
	destroy_construct(child);
	return (result);
}

t_bool				one_less_symbol(t_lst **exec_stack)
{
	t_exec_construct	*current_construct;
	t_exec_construct	*parent_construct;

	current_construct = (void*)get_lst_elem(*exec_stack, 0);
	assert(current_construct != NULL);
	current_construct->remaining_symbols--;
	if (current_construct->remaining_symbols == 0)
	{
		(void)f_lstpop(exec_stack);
		parent_construct = (void*)get_lst_elem(*exec_stack, 0);
		return (give_to_parent(&current_construct, parent_construct));
	}
	else
		return (TRUE);
}

void			give_token(void *token_value,
		t_lst **exec_stack,
		t_exec const *functions_token)
{
	t_exec_construct	*parent;
	void				*final_token;

	if (functions_token != NULL)
	{
		final_token = functions_token->create(token_value);
		parent = (void*)get_lst_elem(*exec_stack, 0);
		parent->functions->give(parent->real, final_token);
	}
	one_less_symbol(exec_stack);
}

t_bool			one_more_prod(t_lst **exec_stack, t_exec const *functions,
		size_t const prod_len)
{
	t_exec_construct	*new_symbol;

	if (functions != NULL)
	{
		new_symbol = create_construct(functions);
		if (new_symbol != NULL)
		{
			new_symbol->real = new_symbol->functions->create(NULL);
			if (new_symbol->real == NULL
					|| NULL == f_lstpush(new_symbol, exec_stack))
				destroy_construct(&new_symbol);
			else
				new_symbol->remaining_symbols = prod_len;
		}
	}
	return (functions == NULL || new_symbol != NULL);
}
