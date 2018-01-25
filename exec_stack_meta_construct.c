/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_stack_meta_construct.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 12:48:56 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/25 12:48:56 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_construct_defs.h"
#include "libft.h"

/*
** The "meta construct is the one that will be on the bottom of the exec stack,
** always.
** It allows to treat the operation of the parser as a cleaner loop invariant,
** whithout making an exception for the grammar start symbol.
** At termination, the real value of the meta_construct will contain the return
** of the 'create' function of the grammar start symbol.
**
** This construct has a prod_len of 2 : construct given as argument to
** execute_construct, and the end_of_input token.
*/

static t_bool		give_to_meta_construct(
		void *meta_construct_ref, void *start_symbol)
{
	void	**ref;

	ref = meta_construct_ref;
	*ref = start_symbol;
	return (TRUE);
}

t_exec_construct		*create_init_meta_construct(void **ref)
{
	t_exec_construct	*meta_construct;
	t_exec const		meta_functions = {.give = give_to_meta_construct};
	size_t const		start_symbol_plus_end_of_input = 2;

	meta_construct = create_construct(&meta_functions);
	if (meta_construct != NULL)
	{
		meta_construct->remaining_symbols = start_symbol_plus_end_of_input;
		meta_construct->real = ref;
	}
	return (meta_construct);
}
