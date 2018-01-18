/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_parsing_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:32:37 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/18 18:32:37 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar_defs.h"
#include "sym_interface.h"
#include <stddef.h>

static t_bool	init_parse_row(void *sym, va_list args)
{
	return (init_sym_parse_table(sym, va_arg(args, size_t)));
}

static t_bool	fill_parse_row(void *sym, va_list args)
{
	return (fill_sym_parse_table(sym, va_arg(args, char const**)));
}

t_bool			compute_parsing_table(
		t_grammar *gram, char const **tokens_names)
{
	return (f_fifoiterr_va(gram->sym_list,
				init_parse_row, ft_string_array_count(tokens_names) + 1)
			&& f_fifoiterr_va(gram->sym_list,
				fill_parse_row, tokens_names));
}
