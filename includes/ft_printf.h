/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:58:40 by mgautier          #+#    #+#             */
/*   Updated: 2017/01/26 15:00:50 by mgautier         ###   ########.fr       */
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
	t_bool			required;
	void			*data;
}				t_req_arg;

typedef struct	s_format_string
{
	t_lst		*required_arguments;
	void		*arguments;
	t_bool		positional_args;
	va_list		*arg_list;
}				t_format_string;

struct			s_flags
{
	t_bool	alternate_form;
	t_bool	zero_padding;
	t_bool	inverse_padding;
	t_bool	blank_before_signed;
	t_bool	explicit_signed;
	t_bool	thousands_grouping;
};

typedef struct	s_conversion t_conversion;
struct	s_conversion
{
	struct s_flags		flags;
	unsigned int		arg_index;
	int					field_width;
	int					precision;
	short				length_modifier;
	int					(*convert_count)(t_conversion *self);
	char				*(*convert)(t_conversion *self);
	t_format_string		*format_string;
};

#endif
