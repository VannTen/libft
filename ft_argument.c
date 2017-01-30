/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argument.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 16:04:52 by mgautier          #+#    #+#             */
/*   Updated: 2017/01/30 11:42:34 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t			ft_set_arg_positional(const char *arg_specifier,
								t_conversion *convers_specs)
{
	size_t	param_length;

	param_length = ft_is_positional(arg_specifier);
	if (param_length != NO_POSITIONAL)
		convers_specs->arg_index = ft_atoi_strict(arg_specifier);
	return (param_length);
}

static size_t	ft_is_positionnal(const char *arg_specifier)
{
	size_t	index;

	index = 0;
	while (arg_specifier[index] != '\0' && ft_isdigit(arg_specifier[index]))
		index++;
	if (arg_specifier[index] == '$')
		return (index);
	else
		return (NO_POSITIONAL);
}
