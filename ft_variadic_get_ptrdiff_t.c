/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_variadic_get_ptrdiff_t.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 12:43:44 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/09 13:05:56 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>

void	put_ptrdiff_t_arg(va_list *arg_list)
{
	va_arg(*arg_list, ptrdiff_t);
}

/*
void	put_uptrdiff_t_arg(va_list *arg_list)
{
	va_arg(*arg_list, unsigned ptrdiff_t);
}
*/

void	put_ptrdiff_t_ptr_arg(va_list *arg_list)
{
	va_arg(*arg_list, ptrdiff_t*);
}
