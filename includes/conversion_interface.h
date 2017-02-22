/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_interface.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 10:23:37 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/22 10:29:24 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_INTERFACE_H
# define CONVERSION_INTERFACE_H
# include "format_string_interface.h"
# include <stdlib.h>

struct	s_conversion;
typedef struct	s_conversion t_conversion;

size_t			conversion_parser(const char *conversion_text, size_t index,
							t_format_string *format_string);

#endif
