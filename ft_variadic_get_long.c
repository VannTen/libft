/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_variadic_get_long.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 12:43:44 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/23 18:43:49 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

void	*put_long_param(va_list *arg_list)
{
	long *ptr;

	ptr = malloc(sizeof(long));
	if(ptr != NULL)
		*ptr = va_arg(*arg_list, long);
	return (ptr);
}

void	*put_ulong_param(va_list *arg_list)
{
	unsigned long *ptr;

	ptr = malloc(sizeof(unsigned long));
	if(ptr != NULL)
		*ptr = va_arg(*arg_list, unsigned long);
	return (ptr);
}

void	*put_long_ptr_param(va_list *arg_list)
{
	long* *ptr;

	ptr = malloc(sizeof(long*));
	if(ptr != NULL)
		*ptr = va_arg(*arg_list, long*);
	return (ptr);
}
