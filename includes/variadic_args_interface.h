/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variadic_args_interface.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 10:34:04 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/24 12:19:28 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARIADIC_ARGS_INTERFACE_H
# define VARIADIC_ARGS_INTERFACE_H
# include "fifo.h"
# include <stdarg.h>

struct s_var_arg;
typedef struct s_var_arg	t_var_arg;

t_var_arg		*ft_get_var_args(t_fifo *conv_list, va_list *var_arg_list);
t_var_arg		*ft_arg_list_ctor(size_t arg_nbr);
void			ft_arg_list_dtor(t_var_arg *array, size_t size);
void			ft_set_types(t_var_arg *args_array, t_lst *conversion_list,
		size_t args_number);
void			ft_fill_args_array(t_var_arg *arg_list, va_list *var_args,
		size_t size);
#endif
