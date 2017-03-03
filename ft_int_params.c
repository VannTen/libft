/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 12:27:03 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/03 12:44:04 by mgautier         ###   ########.fr       */
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

size_t			set_int_params(const char *conversion_specifier,
		t_int_param *numeric_param, t_format_string *format_string)
{
	size_t	index_param;
	size_t	index;

	index = 0;
	if (conversion_specifier[index] == IS_ARG_INDICATOR)
	{
		numeric_param->is_arg = TRUE;
		index++;
		index_param = ft_set_arg_positional(conversion_specifier + index,
				&numeric_param->value);
		if (index_param == 0)
			numeric_param->value = ft_request_arg(format_string);
		else
			index += index_param;
	}
	else
	{
		numeric_param->is_arg = FALSE;
		numeric_param->value = ft_atoi(conversion_specifier + index);
		while (ft_isdigit(conversion_specifier[index])
				|| conversion_specifier[index] == '-')
			index++;
	}
	return (index);
}
