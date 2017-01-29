/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argument.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 16:04:52 by mgautier          #+#    #+#             */
/*   Updated: 2017/01/29 17:22:51 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_arg_index(char *arg_specifier, t_format_string *format)
{
	if (ft_is_positional(*conversion_specifier))
	{
		format->use_positionals = TRUE;
		convers_specs->arg_index = ft_atoi(conversion_specifier);
	}
	else
		format->use_non_positionals = TRUE;
	if (format->use_positionals && format->use_non_positionals)
		return (ERR_POSITIONAL_COHERENCE);
}
