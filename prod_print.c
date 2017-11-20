/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 19:20:16 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/20 10:07:01 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prods_defs.h"
#include "sym_interface.h"
#include <stdarg.h>

static void	iter(void const *sym, va_list args)
{
	ft_dprintf(
			va_arg(args, int),
			"%s%s",
			va_arg(args, char const*),
			get_name(sym));
}

static void	print_it(t_prod const *prod, int const fd, char const *sep)
{
	ft_putstr_fd(get_name(f_lst_first_elem(prod->sym_list)), fd);
	f_lstiter_va(advance_list(prod->sym_list, 1), iter, fd, sep);
}

void		print_prod(t_prod const *prod, int const fd)
{
	print_it(prod, fd, ", ");
}

void		print_prod_back(t_prod const *prod, int const fd)
{
	print_it(prod, fd, " ");
}
