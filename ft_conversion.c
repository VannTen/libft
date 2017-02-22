/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 12:23:57 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/22 15:05:53 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_interface.h"
#include "ft_set_params.h"
#include <stdlib.h>

size_t	*conversion_parser(const char *conversion_text, size_t index)
{
	t_conversion	*conversion;

	conversion = ctor();
	if (conversion == NULL)
		return (0);
	index = set_positional_arg(conversion_text, index, conversion);
	index = set_flags(conversion_text, index, conversion);
	index = set_field_width(conversion_text, index, conversion);
	index = set_precision(conversion_text, index, conversion);
	index = set_length_modifier(conversion_text, index, conversion);
	index = set_type_conversion(conversion_text, index, conversion);
	return (conversion);
}



