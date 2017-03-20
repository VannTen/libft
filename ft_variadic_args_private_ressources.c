/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_variadic_args_private_ressources.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 11:30:07 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/20 11:36:31 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variadic_args_defs.h"

void			ft_arg_list_dtor(t_var_arg *array, size_t size)
{
	size_t	index;

	index = 0;
	while (index < size)
	{
		array[index].parameter.t_intmax_t = 0;
		array[index].type = UNKNOWN_TYPE;
		index++;
	}
	free(array);
}

t_var_arg		*ft_arg_list_ctor(size_t arg_nbr)
{
	t_var_arg	*arg_array;
	size_t		index;

	index = 0;
	arg_array = malloc(sizeof(t_var_arg) * (arg_nbr));
	if (arg_array != NULL)
	{
		while (index < arg_nbr)
		{
			arg_array[index].type = UNKNOWN_TYPE;
			index++;
		}
	}
	return (arg_array);
}
