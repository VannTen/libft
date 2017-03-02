/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_var_args_private_const.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 12:51:43 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/02 13:24:03 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variadic_args_defs.h"

int				ft_get_int(const t_var_arg *var_arg)
{
	return (var_arg->parameter.t_int);
}

const t_var_arg	*ft_get_address(const t_var_arg *array, size_t index)
{
	return (array + index);
}
