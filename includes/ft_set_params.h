/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_params.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 18:03:13 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/22 18:15:53 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SET_PARAMS_H
# define FT_SET_PARAMS_H
# include "conversion_interface.h"
# include "format_string_interface.h"
# include <stdlib.h>

size_t			set_positional_arg(const char *format_string, size_t index,
		t_conversion *conversion);
size_t			set_flags(const char *format_string, size_t index,
		t_conversion *conversion);

/*
** Following functions needs a ref to format_string
*/

size_t			set_field_width(const char *format_string, size_t index,
		t_conversion *conversion, t_format_string *fmt);
size_t			set_precision(const char *format_string, size_t index,
		t_conversion *conversion, t_format_string *fmt);
size_t			set_length_modifier(const char *format_string, size_t index,
		t_conversion *conversion, t_format_string *fmt);
size_t		set_type_conversion(const char *conversion_specifier, size_t index,
		t_conversion *conversion, t_format_string *fmt);

#endif
