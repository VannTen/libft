/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_string_interface.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 10:10:08 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/22 12:48:12 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_STRING_INTERFACE_H
# define FORMAT_STRING_INTERFACE_H
#include "conversion_interface.h"
#include "bool.h"

struct s_format_string;
typedef struct s_format_string t_format_string;

t_format_string	*ft_format_string_parser(const char *string);
int				ft_request_arg(t_format_string *format);
t_bool			f_push_conv_to_fmt(t_format_string *fmt, t_conversion *conv);
#endif
