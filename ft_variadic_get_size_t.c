/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_variadic_get_size_t.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 12:43:44 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/23 18:43:50 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>

void	*put_size_t_param(va_list *arg_list)
{
	size_t *ptr;

	ptr = malloc(sizeof(size_t));
	if(ptr != NULL)
		*ptr = va_arg(*arg_list, size_t);
	return (ptr);
}

void	*put_size_t_ptr_param(va_list *arg_list)
{
	size_t* *ptr;

	ptr = malloc(sizeof(size_t*));
	if(ptr != NULL)
		*ptr = va_arg(*arg_list, size_t*);
	return (ptr);
}
