/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_variadic_get_intmax_t.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 12:43:44 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/23 18:43:49 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdint.h>

void	*put_intmax_t_param(va_list *arg_list)
{
	intmax_t *ptr;

	ptr = malloc(sizeof(intmax_t));
	if(ptr != NULL)
		*ptr = va_arg(*arg_list, intmax_t);
	return (ptr);
}

void	*put_uintmax_t_param(va_list *arg_list)
{
	uintmax_t *ptr;

	ptr = malloc(sizeof(uintmax_t));
	if(ptr != NULL)
		*ptr = va_arg(*arg_list, uintmax_t);
	return (ptr);
}

void	*put_intmax_t_ptr_param(va_list *arg_list)
{
	intmax_t* *ptr;

	ptr = malloc(sizeof(intmax_t*));
	if(ptr != NULL)
		*ptr = va_arg(*arg_list, intmax_t*);
	return (ptr);
}
