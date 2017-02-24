/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_variadic_get_size_t.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 12:43:44 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/24 12:02:21 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variadic_args_defs.h"
#include <stdarg.h>
#include <stddef.h>

void	put_size_t_param(t_var_arg *param, va_list *arg_list)
{
	param->parameter.t_size_t = va_arg(*arg_list, size_t);
}

void	put_size_t_ptr_param(t_var_arg *param, va_list *arg_list)
{
	param->parameter.t_ptr_size_t = va_arg(*arg_list, size_t*);
}
