/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_specifier.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 18:45:00 by mgautier          #+#    #+#             */
/*   Updated: 2017/01/30 14:57:50 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"
# include "libft.h"

static t_bool	set_one_flag(const char *conversion_specifier, size_t index,
		t_conversion *convers_specs)
{
	size_t	index_flags;

	index_flags = 0;
	while (index_flags < FLAGS_NBR
			&& conversion_specifier[index] != flags[index_flags])
		index_flags++;
	if (index_flags != FLAGS_NBR)
	{
		convers_specs->flags[index_flags] = TRUE;
		return (TRUE)
	}
	else
		return (FALSE);
}

size_t			set_positional_arg(const char *conversion_specifier,
		size_t index, t_conversion *convers_spec)
{
	return (ft_set_arg_positional(conversion_specifier, index,
				&convers_specs->arg_index));
}

size_t			set_flags(const char *conversion_specifier, size_t index,
		t_conversion *convers_specs)
{
	while (set_one_flag(conversion_specifier, index, convers_specs))
		index++;
	return (index);
}

size_t			set_field_width(const char *conversion_specifier, size_t index,
		t_conversion *convers_specs)
{
	return (set_int_args(conversion_specifier, index,
				&convers_specs->field_width, convers_specs->format_string));
}

size_t			set_precision(const char *conversion_specifier, size_t index,
		t_conversion *convers_specs)
{
	return (set_int_args(conversion_specifier, index,
				&convers_specs->precision, convers_specs->format_string));
}
