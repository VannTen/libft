/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_variadic_get_wchar_t.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 13:47:07 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/23 18:43:50 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <wchar.h>

void	*put_wint_param(va_list *arg_list)
{
	wint_t *ptr;

	ptr = malloc(sizeof(wint_t));
	if(ptr != NULL)
		*ptr = va_arg(*arg_list, wint_t);
	return (ptr);
}

void	*put_wchar_str_param(va_list *arg_list)
{
	wchar_t* *ptr;

	ptr = malloc(sizeof(wchar_t*));
	if(ptr != NULL)
		*ptr = va_arg(*arg_list, wchar_t*);
	return (ptr);
}
