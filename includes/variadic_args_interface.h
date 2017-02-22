/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variadic_args_interface.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 10:34:04 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/22 10:35:34 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARIADIC_ARGS_INTERFACE_H
# define VARIADIC_ARGS_INTERFACE_H
# include "fifo.h"
# include <stdarg.h>

struct	s_var_arg;
typedef struct s_var_arg t_var_arg;

t_var_arg		*ft_get_var_args(t_fifo *conv_list, va_list *var_arg_list);
#endif
