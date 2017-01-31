/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argument.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 19:01:11 by mgautier          #+#    #+#             */
/*   Updated: 2017/01/31 18:36:23 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARGUMENT_H
# define FT_ARGUMENT_H

# include "ft_printf.h"
# include <stdlib.h>
# define IS_ARG_INDICATOR '*'

size_t		set_int_args(const char *conversion_specifier, size_t index,
		t_int_arg *int_arg, t_format_string *format_string);

int			ft_request_arg(t_format_string *format);
#endif
