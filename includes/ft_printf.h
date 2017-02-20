/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:58:40 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/20 15:15:53 by mgautier         ###   ########.fr       */
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

typedef struct	s_format_string
{
	t_fifo			*conversion_list;
	int				arg_count;
	size_t			length;
	size_t			conversions_length;
}				t_format_string;

typedef struct	s_int_arg
{
	t_bool	is_arg;
	int		value;
}				t_int_arg;

typedef struct	s_conversion
{
	t_bool				flags[FLAGS_NBR];
	int					arg_index;
	t_int_arg			field_width;
	t_int_arg			precision;
	int					length_modifier;
	enum e_conv_type	type;
	t_format_string		*format_string;
}				t_conversion;

size_t			conversion_parser(const char *conversion_text, size_t index,
							t_format_string *format_string);
t_format_string	*ft_format_string_parser(const char *string);
#endif
