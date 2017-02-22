/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_interface.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 10:23:37 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/22 16:14:49 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_INTERFACE_H
# define CONVERSION_INTERFACE_H
# include "bool.h"
# include <stdlib.h>

struct	s_conversion;
typedef struct	s_conversion t_conversion;

t_conversion	*conversion_parser(const char *conversion_text, size_t index);
size_t			set_positional_arg(const char *conversion_specifier,
		size_t index, t_conversion *convers_specs);
t_conversion	*conversion_ctor(void);
t_bool			set_one_flag(const char *conv_string, size_t index,
		t_conversion *conv);
unsigned int	ft_arg_required(const void *conversion);

#endif
