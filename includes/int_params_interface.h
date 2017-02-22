/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_params_interface.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 10:26:32 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/22 12:34:38 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT_PARAMS_INTERFACE_H
# define INT_PARAMS_INTERFACE_H
# include "format_string_interface.h"

struct	s_int_param;
typedef struct s_int_param t_int_param;

size_t			set_int_params(const char *conversion_specifier, size_t index,
		t_int_param *numeric_param, t_format_string *format_string);
#endif
