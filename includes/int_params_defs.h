/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_params_defs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 10:25:10 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/10 13:21:45 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT_PARAMS_DEFS_H
# define INT_PARAMS_DEFS_H
# include "int_params_interface.h"
# include "bool.h"

struct	s_int_param
{
	t_bool		is_arg;
	union
	{
		size_t	arg_index;
		int		value;
	}			param;
};

/*
** This function are used internally but do not access the object
*/

int	ft_set_arg_positional(const char *arg_specifier, size_t *conv_spec);
#endif
