/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_parse_table_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 21:19:43 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/21 21:19:43 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_interface.h"
#include "libft.h"
#include "test_interface.h"

t_bool	fill_syms_parse_table(t_symbol **syms, size_t nb_syms,
		char const **tokens)
{
	size_t	index;
	size_t	nb_tokens;

	index = 0;
	nb_tokens = ft_string_array_count(tokens) + 1;
	while (index < nb_syms && init_sym_parse_table(syms[index], nb_tokens))
		index++;
	if (index < nb_syms)
		return (FALSE);
	index = 0;
	while (index < nb_syms && fill_sym_parse_table(syms[index], tokens))
		index++;
	return (index == nb_syms);
}

static t_bool	compute_sym_first(void *sym, va_list args)
{
	return (compute_sym_first_set(sym, va_arg(args, t_bool*)));
}

static t_bool	follow_from_first(void *sym)
{
	return (compute_follow_from_first_in_sym(sym));
}

static t_bool	follow_from_follow(void *sym, va_list args)
{
	return (compute_follow_sym_step_3(sym, va_arg(args, t_bool*)));
}

t_bool	compute_sets_all_syms(t_fifo *tokens, t_fifo *sym)
{
	t_bool	sym_added;

	sym_added = TRUE;
	if (!f_fifoiterr_va(tokens, compute_sym_first, &sym_added))
		return (FALSE);
	while (sym_added)
	{
		sym_added = FALSE;
		if (!f_fifoiterr_va(sym, compute_sym_first, &sym_added))
			return (FALSE);
	}
	sym_added = TRUE;
	if (add_one_to_follow((void*)get_fifo_elem(sym, 0),
				create_symbol("END_OF_INPUT"), &sym_added))
	{
		if (f_fifoiterr(sym, follow_from_first))
		{
			while (f_fifoiterr_va(sym,
						follow_from_follow, &sym_added)
					&& sym_added)
				sym_added = FALSE;
			return (!sym_added);
		}
	}
	return (FALSE);
}
