/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_params_tools.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 13:49:31 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/24 15:10:32 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_is_positional(const char *arg_specifier)
{
	size_t	index;

	index = 0;
	while (ft_isdigit(arg_specifier[index]))
		index++;
	if (arg_specifier[index] == '$')
		return (index + 1);
	else
		return (0);
}

size_t			ft_set_arg_positional(const char *arg_specifier,
		size_t index, int *conv_spec)
{
	size_t	param_length;

	param_length = ft_is_positional(arg_specifier + index);
	if (param_length != 0)
		*conv_spec = ft_atoi(arg_specifier + index) - 1;
	return (index + param_length);
}
