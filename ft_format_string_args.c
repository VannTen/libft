/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_string_args.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 12:28:05 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/07 14:06:42 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>


static void	ft_expected_types(t_var_arg *variadic, t_conversion *conversion)
{
	variadic->type = ft_conv_to_type(conversion);
}

static t_type ft_conv_to_type(t_conversion *conversion)
{
	t_type type;

	type = UNKNOWN_TYPE;
	if (conversion->type == D || conversion->type == I)
		type = INT + conversion->length_modifier;
	else if (conversion->type >= O && conversion->type <= X_MAJ)
		type = U_INT + conversion->length_modifier;
	else if (conversion->type == N)
		type = U_INT + conversion->length_modifier;
	return (type);
}

void		*ft_format_string_args(t_lst *conversion_list, va_list list)
{
	size_t	args_numbers;
	var_arg	*args_array;

	args_numbers = ft_lstmax(conversion_list, &get_arg_index);
	args_array = malloc(sizeof(var_arg*) * args_number + 1);
	if (args_array != NULL)
		ft_fill_args_array(args_array, conversion_list);
	return (args_array);
}
