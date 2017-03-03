/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_params_defs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 10:25:10 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/03 11:57:39 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT_PARAMS_DEFS_H
# define INT_PARAMS_DEFS_H
# include "int_params_interface.h"
# include "bool.h"

struct	s_int_param
{
	t_bool	is_arg;
	int		value;
};

/*
** This function are used internally but do not access the object
*/

size_t	ft_set_arg_positional(const char *arg_specifier, int *conv_spec);
#endif
