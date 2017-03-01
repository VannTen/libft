/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_defs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 10:13:24 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/01 15:37:44 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_DEFS_H
# define CONVERSION_DEFS_H
# include "conversion_interface.h"
# include "conv_types_defs.h"
# include "int_params_defs.h"
# include "flags_defs.h"
# include "length_modifier_defs.h"
# include "bool.h"

struct	s_conversion
{
	t_bool				flags[FLAGS_NBR];
	int					arg_index;
	t_int_param			field_width;
	t_int_param			precision;
	t_length_modifier	length_modifier;
	t_conv_type			type;
	size_t				result_length;
	size_t				specifier_length;
};

#endif
