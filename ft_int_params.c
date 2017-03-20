/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 12:27:03 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/20 10:57:14 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "int_params_defs.h"
#include "format_string_interface.h"
#include "printf_constants.h"
#include "libft.h"
#include <stdlib.h>

/*
** This functions is used to determine field width and precision
*/

int			set_int_params(const char *conversion_specifier,
		t_int_param *numeric_param, t_format_string *format_string)
{
	int	index_param;
	int	index;

	index = 0;
	if (conversion_specifier[index] == IS_ARG_INDICATOR)
	{
		numeric_param->is_arg = TRUE;
		index++;
		index_param = ft_set_arg_positional(conversion_specifier + index,
				&numeric_param->param.arg_index);
		if (index_param == 0)
			numeric_param->param.arg_index = ft_request_arg(format_string);
		else
			index += index_param;
	}
	else
	{
		numeric_param->is_arg = FALSE;
		numeric_param->param.value = ft_strict_atoi(conversion_specifier + index);
		if (conversion_specifier[index] == '-')
			index++;
		while (ft_isdigit(conversion_specifier[index]))
			index++;
	}
	return (index);
}

size_t		param_is_arg(const t_int_param *param)
{
	if (param->is_arg)
		return (param->param.arg_index);
	else
		return (0);
}

void		normalize_int_param(t_int_param *param)
{
	if (param->is_arg)
	{
		if (param->param.arg_index != 0)
			param->param.value--;
		else
		{
			param->index_is_valid = FALSE;
			param->param.value = 0;
		}
	}
}
