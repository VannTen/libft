/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_var_args_private_give.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 09:13:43 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/14 19:14:05 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variadic_args_defs.h"
#include <stdint.h>

intmax_t	ft_var_signed_integers(const t_var_arg *signed_integer)
{
	intmax_t	integer;

	integer = 0;
	if (signed_integer->type >= INT && signed_integer->type <= SHORT)
		integer = signed_integer->parameter.t_int;
	else if (signed_integer->type == LONG)
		integer = signed_integer->parameter.t_long_int;
	else if (signed_integer->type == LONG_LONG)
		integer = signed_integer->parameter.t_long_long_int;
	else if (signed_integer->type == INTMAX)
		integer = signed_integer->parameter.t_intmax_t;
	else if (signed_integer->type == PTRDIFF)
		integer = signed_integer->parameter.t_ptrdiff_t;
	else if (signed_integer->type == SSIZE)
		integer = signed_integer->parameter.t_ssize_t;
	return (integer);
}

uintmax_t	ft_var_unsigned_integers(const t_var_arg *unsigned_integer)
{
	intmax_t	integer;

	integer = 0;
	if (unsigned_integer->type >= U_INT && unsigned_integer->type <= U_SHORT)
		integer = unsigned_integer->parameter.t_uint;
	else if (unsigned_integer->type == U_LONG)
		integer = unsigned_integer->parameter.t_ulong_int;
	else if (unsigned_integer->type == U_LONG_LONG)
		integer = unsigned_integer->parameter.t_ulong_long_int;
	else if (unsigned_integer->type == U_INTMAX)
		integer = unsigned_integer->parameter.t_uintmax_t;
	else if (unsigned_integer->type == PTRDIFF)
		integer = unsigned_integer->parameter.t_ptrdiff_t;
	else if (unsigned_integer->type == SIZE)
		integer = unsigned_integer->parameter.t_size_t;
	return (integer);
}
