/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_string_defs.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 10:08:36 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/22 10:58:03 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_STRING_DEFS_H
# define FORMAT_STRING_DEFS_H
# include "format_string_interface.h"
# include "fifo.h"
# include "variadic_args_interface.h"
# include "bool.h"
# include <stdlib.h>

struct	s_format_string
{
	t_fifo		*conversion_list;
	t_var_arg	*arg_list;
	size_t		arg_count;
	int			length;
	int			conversions_length;
	t_bool		has_error_conversion;
};

#endif
