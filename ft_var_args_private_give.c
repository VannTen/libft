/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_var_args_private_give.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 09:13:43 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/10 10:52:03 by mgautier         ###   ########.fr       */
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
	else if (signed_integer->type == SIZE)
		integer = signed_integer->parameter.t_ssize_t;
	return (integer);
}
