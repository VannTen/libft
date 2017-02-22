/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variadic_args_defs.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 10:32:31 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/22 10:56:22 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARIADIC_ARGS_DEFS_H
# define VARIADIC_ARGS_DEFS_H
# include "variadic_args_defs.h"
# include <stdarg.h>

typedef enum	e_type
{
	UNKNOWN_TYPE,
	INT,
	CHAR,
	SHORT,
	LONG,
	LONG_LONG,
	INTMAX,
	PTRDIFF,
	SIZE,
	QUAD,
	U_INT,
	U_CHAR,
	U_SHORT,
	U_LONG,
	U_LONG_LONG,
	U_INTMAX,
	U_PTRDIFF,
	U_SIZE,
	U_QUAD,
	PTR_INT,
	PTR_CHAR,
	PTR_SHORT,
	PTR_LONG,
	PTR_LONG_LONG,
	PTR_INTMAX,
	PTR_PTRDIFF,
	PTR_SIZE,
	PTR_QUAD
}				t_type;

struct	s_var_arg
{
	va_list	arg;
	t_type	type;
};

#endif
