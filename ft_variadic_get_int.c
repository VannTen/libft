/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_variadic_get_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 12:43:44 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/23 18:43:49 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

void	*put_int_param(va_list *arg_list)
{
	int *ptr;

	ptr = malloc(sizeof(int));
	if(ptr != NULL)
		*ptr = va_arg(*arg_list, int);
	return (ptr);
}

void	*put_uint_param(va_list *arg_list)
{
	unsigned int *ptr;

	ptr = malloc(sizeof(unsigned int));
	if(ptr != NULL)
		*ptr = va_arg(*arg_list, unsigned int);
	return (ptr);
}

void	*put_int_ptr_param(va_list *arg_list)
{
	int* *ptr;

	ptr = malloc(sizeof(int*));
	if(ptr != NULL)
		*ptr = va_arg(*arg_list, int*);
	return (ptr);
}
