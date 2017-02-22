/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_variadic_args.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 12:48:04 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/22 10:39:18 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VARIADIC_ARGS_H
# define FT_VARIADIC_ARGS_H
# include <stdarg.h>
# include <stddef.h>

void		put_int_param(va_list *arg_list);
void		put_long_arg(va_list *arg_list);
void		put_long_long_arg(va_list *arg_list);
void		put_intmax_t_arg(va_list *arg_list);
void		put_ptrdiff_t_arg(va_list *arg_list);
void		put_size_t_arg(va_list *arg_list);
void		put_uint_param(va_list *arg_list);
void		put_ulong_arg(va_list *arg_list);
void		put_ulong_long_arg(va_list *arg_list);
void		put_uintmax_t_arg(va_list *arg_list);
void		put_uptrdiff_t_arg(va_list *arg_list);
void		put_usize_t_arg(va_list *arg_list);
void		put_ptr_int_param(va_list *arg_list);
void		put_ptr_char_arg(va_list *arg_list);
void		put_ptr_short_arg(va_list *arg_list);
void		put_ptr_long_arg(va_list *arg_list);
void		put_ptr_long_long_arg(va_list *arg_list);
void		put_ptr_intmax_t_arg(va_list *arg_list);
void		put_ptr_ptrdiff_t_arg(va_list *arg_list);
void		put_ptr_size_t_arg(va_list *arg_list);
typedef void	(*t_var_advance)(va_list *);
static const t_var_advance	g_advance_by[] = {
	&put_int_param,
	&put_int_param,
	&put_int_param,
	&put_int_param,
	&put_long_arg,
	&put_long_long_arg,
	&put_intmax_t_arg,
	&put_ptrdiff_t_arg,
	&put_size_t_arg,
	NULL,
	&put_uint_param,
	&put_int_param,
	&put_int_param,
	&put_ulong_arg,
	&put_ulong_long_arg,
	&put_uintmax_t_arg,
	&put_uptrdiff_t_arg,
	&put_usize_t_arg,
	NULL,
	&put_ptr_int_param,
	&put_ptr_char_arg,
	&put_ptr_short_arg,
	&put_ptr_long_arg,
	&put_ptr_long_long_arg,
	&put_ptr_intmax_t_arg,
	&put_ptr_ptrdiff_t_arg,
	&put_ptr_size_t_arg,
	NULL
};

#endif
