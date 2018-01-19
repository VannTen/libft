/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_first_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 18:02:28 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/19 18:02:28 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prods_interface.h"
#include "libft.h"

static char const	*g_str_symbol[] = {
	"A B C",
	"SYM SYM_B",
	"",
	"SYM SYM_1 SYM_C",
	"SYM: SYM_2 SYM_3 SYM_4",
	"|SYM_1 SYM_B",
	"SYM_1: A B C | D E F |",
	"SYM_B: G |"
};

static char const	*g_first_set[] = {
	"A",
	"SYM_2 A D G EMPTY",
	"EMPTY",
	"SYM_2 A D G SYM_C"
};

static t_bool		test_prod_first_set(t_prod **prod, t_symbol **sym, ...)
{
	t_lst	*first_sets;

	first_sets = str_to_first_set_lst(g_first_set, ARRAY_LENGTH(g_first_set));

	return (TRUE);
}

int	main(void)
{
	return (test_sym_prod(
				g_str_symbol,
				ARRAY_LENGTH(g_str_symbol)
				- (ARRAY_LENGTH(g_str_symbol) - ARRAY_LENGTH(g_first_set)),
				ARRAY_LENGTH(g_str_symbol) - ARRAY_LENGTH(g_first_set),
				test_prod_first_set));
}
