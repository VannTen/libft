/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_params_tools.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 13:49:31 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/10 17:33:50 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_is_positional(const char *arg_specifier)
{
	int	index;

	index = 0;
	while (ft_isdigit(arg_specifier[index]))
		index++;
	if (arg_specifier[index] == '$')
		return (index + 1);
	else
		return (0);
}

int			ft_set_arg_positional(const char *arg_specifier, size_t *conv_spec)
{
	int	param_length;

	param_length = ft_is_positional(arg_specifier);
	if (param_length != 0)
		*conv_spec = ft_strict_atoi(arg_specifier);
	return (param_length);
}
