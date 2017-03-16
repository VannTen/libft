/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_variadic_get_short.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 12:43:44 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/16 18:51:43 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variadic_args_defs.h"
#include <stdarg.h>

void	put_short_ptr_param(t_var_arg *param, va_list *arg_list)
{
	param->parameter.t_ptr_short = va_arg(*arg_list, short*);
}

void	put_short_param(t_var_arg *param, va_list *arg_list)
{
	param->parameter.t_short = va_arg(*arg_list, int);
}

void	put_ushort_param(t_var_arg *param, va_list *arg_list)
{
	param->parameter.t_ushort = va_arg(*arg_list, int);
}
