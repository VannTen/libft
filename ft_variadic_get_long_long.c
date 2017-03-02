/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_ptr_variadic_get_long_long.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 12:43:44 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/02 16:01:53 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variadic_args_defs.h"
#include <stdarg.h>

void	put_long_long_param(t_var_arg *param, va_list *arg_list)
{
	param->parameter.t_long_long_int = va_arg(*arg_list, long long);
}

void	put_ulong_long_param(t_var_arg *param, va_list *arg_list)
{
	param->parameter.t_ulong_long_int = va_arg(*arg_list, unsigned long long);
}

void	put_long_long_ptr_param(t_var_arg *param, va_list *arg_list)
{
	param->parameter.t_ptr_long_long_int = va_arg(*arg_list, long long*);
}
