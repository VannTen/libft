/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:58:40 by mgautier          #+#    #+#             */
/*   Updated: 2017/01/30 15:00:05 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "bool.h"
# include "list.h"
# include <stdarg.h>

typedef	struct	s_req_arg
{
	unsigned int	arg_index;
	unsigned int	required;
}				t_req_arg;

typedef struct	s_format_string
{
	char			*string;
	t_fifo			*conversion_list;
	void			*arguments;
	unsigned int	last_required_arg;
	unsigned int	arg_count;
	va_list			arg_list;
}				t_format_string;

typedef struct	s_int_arg
{
	t_bool	is_arg;
	int		value;
}				t_int_arg

typedef struct	s_conversion t_conversion;
struct	s_conversion
{
	t_bool				flags[NBR_OF_FLAGS];
	unsigned int		arg_index;
	t_int_arg			field_width;
	t_int_arg			precision;
	short				length_modifier;
	int					(*convert_count)(t_conversion *self);
	char				*(*convert)(t_conversion *self);
	t_format_string		*format_string;
};

#endif
