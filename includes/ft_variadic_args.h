/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_variadic_params.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 12:48:04 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/24 10:38:28 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VARIADIC_PARAMS_H
# define FT_VARIADIC_PARAMS_H
# include <stdarg.h>
# include <stddef.h>

void		put_int_param(t_var_arg *param, va_list *arg_list);
void		put_long_param(t_var_arg *param, va_list *arg_list);
void		put_long_long_param(t_var_arg *param, va_list *arg_list);
void		put_intmax_t_param(t_var_arg *param, va_list *arg_list);
void		put_ptrdiff_t_param(t_var_arg *param, va_list *arg_list);
void		put_size_t_param(t_var_arg *param, va_list *arg_list);
void		put_uint_param(t_var_arg *param, va_list *arg_list);
void		put_ulong_param(t_var_arg *param, va_list *arg_list);
void		put_ulong_long_param(t_var_arg *param, va_list *arg_list);
void		put_uintmax_t_param(t_var_arg *param, va_list *arg_list);
void		put_int_ptr_param(t_var_arg *param, va_list *arg_list);
void		put_char_ptr_param(t_var_arg *param, va_list *arg_list);
void		put_short_ptr_param(t_var_arg *param, va_list *arg_list);
void		put_long_ptr_param(t_var_arg *param, va_list *arg_list);
void		put_long_long_ptr_param(t_var_arg *param, va_list *arg_list);
void		put_intmax_t_ptr_param(t_var_arg *param, va_list *arg_list);
void		put_ptrdiff_t_ptr_param(t_var_arg *param, va_list *arg_list);
void		put_size_t_ptr_param(t_var_arg *param, va_list *arg_list);
typedef void	(*t_var_advance)(t_var_arg *param, va_list *);
static const t_var_advance	g_get_arg_of_type[] = {
	&put_int_param,
	&put_int_param,
	&put_int_param,
	&put_int_param,
	&put_long_param,
	&put_long_long_param,
	&put_intmax_t_param,
	&put_ptrdiff_t_param,
	&put_size_t_param,
	NULL,
	&put_uint_param,
	&put_int_param,
	&put_int_param,
	&put_ulong_param,
	&put_ulong_long_param,
	&put_uintmax_t_param,
	&put_ptrdiff_t_param,
	&put_size_t_param,
	NULL,
	&put_int_ptr_param,
	&put_char_ptr_param,
	&put_short_ptr_param,
	&put_long_ptr_param,
	&put_long_long_ptr_param,
	&put_intmax_t_ptr_param,
	&put_ptrdiff_t_ptr_param,
	&put_size_t_ptr_param,
	NULL
};

#endif
