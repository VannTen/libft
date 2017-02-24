/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_variadic_get_wchar_t.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 13:47:07 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/24 12:04:38 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variadic_args_defs.h"
#include <stdarg.h>
#include <wchar.h>

void	put_wint_param(t_var_arg *param, va_list *arg_list)
{
	param->parameter.t_wint_t = va_arg(*arg_list, wint_t);
}

void	put_wstring_param(t_var_arg *param, va_list *arg_list)
{
	param->parameter.t_wstring = va_arg(*arg_list, wchar_t*);
}
