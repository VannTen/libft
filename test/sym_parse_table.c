/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_parse_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 17:51:29 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/21 17:51:29 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_interface.h"
#include "test_interface.h"
#include "libft.h"
#define NB_SYM ARRAY_LENGTH(g_sym)

static char const	*g_sym[] = {
	"SYM: A B | SYM_2 W ",
	"SYM_2: X Y | N M |"
};

static char const	*g_tokens[] = {"A", "B", "W", "X", "Y", "N", "M", NULL};

static char const	*g_parse_row[][ARRAY_LENGTH(g_tokens)] = {
	{"A B", NULL, "SYM_2 W", "SYM_2 W", NULL, "SYM_2 W", NULL, NULL},
	{NULL, NULL, "", "X Y", NULL, "N M", NULL, NULL}
};

static t_bool		equ(void const *sym, void const *str)
{
	return (ft_strequ(get_name(sym), str));
}

t_bool				one_prod_parse_correct(
		t_prod const *prod,
		char const *prod_str)
{
	t_lst	*prod_cmp;
	t_bool	result;

	if (prod == NULL || prod_str == NULL)
		return (prod == NULL && prod_str == NULL);
	if (ft_strequ(prod_str, "") && get_prod_len(prod) == 0)
		return (TRUE);
	prod_cmp = f_strsplit_lst(prod_str, ' ');
	result = lst_equ(get_prod_lst(prod), prod_cmp, equ);
	f_lstdel(&prod_cmp, ft_gen_strdel);
	return (result);
}

t_bool				parse_row_is_correct(t_symbol *sym, char const **cmp)
{
	size_t				index;
	t_prod const *const	*parse_row;

	index = 0;
	parse_row = get_sym_parse_row(sym);
	while (index < ARRAY_LENGTH(g_tokens)
			&& one_prod_parse_correct(parse_row[index], cmp[index]))
		index++;
	return (index == ARRAY_LENGTH(g_tokens));

}

t_bool				test_sym_parse_table(
		__attribute__((unused))t_prod **prod, t_symbol **sym, ...)
{
	size_t	index;

	(void)compute_first_sets(sym, NB_SYM);
	(void)compute_follow_sets(sym, NB_SYM);
	(void)fill_syms_parse_table(sym, NB_SYM, g_tokens);
	index = 0;
	while (index < ARRAY_LENGTH(g_sym)
			&& parse_row_is_correct(sym[index], g_parse_row[index]))
		index++;
	return (index == ARRAY_LENGTH(g_sym));
}

int					main(void)
{
	RET_TEST(test_sym_prod(
				g_sym,
				ARRAY_LENGTH(g_sym) - NB_SYM,
				NB_SYM,
				test_sym_parse_table));
}
