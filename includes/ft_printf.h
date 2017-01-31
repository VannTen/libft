/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:58:40 by mgautier          #+#    #+#             */
/*   Updated: 2017/01/31 14:05:54 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "ft_types.h"
# include "ft_flags.h"
# include "bool.h"
# include "libft.h"
# include <stdarg.h>
# define CONVERSION_INDICATOR '%'

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
	int				arg_count;
	va_list			arg_list;
}				t_format_string;

typedef struct	s_int_arg
{
	t_bool	is_arg;
	int		value;
}				t_int_arg;

typedef struct	s_conversion t_conversion;
struct	s_conversion
{
	t_bool				flags[FLAGS_NBR];
	int					arg_index;
	t_int_arg			field_width;
	t_int_arg			precision;
	short				length_modifier;
	enum e_conv_type	type;
	t_format_string		*format_string;
};

#endif
