/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_variadic_args.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 12:48:04 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/09 17:58:11 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VARIADIC_ARGS_H
# define FT_VARIADIC_ARGS_H
# include <stdarg.h>
# include <stddef.h>

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

void		put_int_arg(va_list *arg_list);
void		put_long_arg(va_list *arg_list);
void		put_long_long_arg(va_list *arg_list);
void		put_intmax_t_arg(va_list *arg_list);
void		put_ptrdiff_t_arg(va_list *arg_list);
void		put_size_t_arg(va_list *arg_list);
void		put_uint_arg(va_list *arg_list);
void		put_ulong_arg(va_list *arg_list);
void		put_ulong_long_arg(va_list *arg_list);
void		put_uintmax_t_arg(va_list *arg_list);
void		put_uptrdiff_t_arg(va_list *arg_list);
void		put_usize_t_arg(va_list *arg_list);
void		put_ptr_int_arg(va_list *arg_list);
void		put_ptr_char_arg(va_list *arg_list);
void		put_ptr_short_arg(va_list *arg_list);
void		put_ptr_long_arg(va_list *arg_list);
void		put_ptr_long_long_arg(va_list *arg_list);
void		put_ptr_intmax_t_arg(va_list *arg_list);
void		put_ptr_ptrdiff_t_arg(va_list *arg_list);
void		put_ptr_size_t_arg(va_list *arg_list);
typedef void	(*t_var_advance)(va_list *);
static const t_var_advance	g_advance_by[] = {
	&put_int_arg,
	&put_int_arg,
	&put_int_arg,
	&put_int_arg,
	&put_long_arg,
	&put_long_long_arg,
	&put_intmax_t_arg,
	&put_ptrdiff_t_arg,
	&put_size_t_arg,
	NULL,
	&put_uint_arg,
	&put_int_arg,
	&put_int_arg,
	&put_ulong_arg,
	&put_ulong_long_arg,
	&put_uintmax_t_arg,
	&put_uptrdiff_t_arg,
	&put_usize_t_arg,
	NULL,
	&put_ptr_int_arg,
	&put_ptr_char_arg,
	&put_ptr_short_arg,
	&put_ptr_long_arg,
	&put_ptr_long_long_arg,
	&put_ptr_intmax_t_arg,
	&put_ptr_ptrdiff_t_arg,
	&put_ptr_size_t_arg,
	NULL
};


typedef struct	s_var_arg
{
	va_list	arg;
	t_type	type;
}				t_var_arg;

#endif
