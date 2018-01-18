/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_parse_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 19:17:14 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/18 19:17:14 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_defs.h"
#include "prods_interface.h"

t_bool			init_sym_parse_table(t_symbol *sym, size_t nb_tokens)
{
	size_t	index;

	sym->parse_row = malloc(sizeof(*parse_row) * nb_tokens);
	if (sym->parse_row != NULL)
	{
		index = 0;
		while (index < nb_tokens)
		{
			parse_row[index] = NULL;
			index++;
		}
	}
	return (sym->parse_row != NULL);
}

static t_bool	add_to_parse_row(void *prod, va_list args)
{
	t_symbol	*sym;
	char const	**token_names;

	sym = va_arg(arg, t_symbol*);
	token_names = va_arg(arg, char const**);
	return (add_from_prod_to_parse_table(prod, sym, token_names));
}

t_bool			fill_sym_parse_table(t_symbol *sym, char const **token_names)
{
	return (f_lstiterr_va(sym->prods,
				add_to_parse_row, sym, tokens_name));
}
