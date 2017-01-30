/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argument.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 19:01:11 by mgautier          #+#    #+#             */
/*   Updated: 2017/01/30 19:03:07 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARGUMENT_H
# define FT_ARGUMENT_H

# include "ft_printf.h"
# include <stdlib.h>

size_t		set_int_args(const char *conversion_specifier, size_t index,
		t_int_arg *int_arg, t_format_string *format_string);

#endif
