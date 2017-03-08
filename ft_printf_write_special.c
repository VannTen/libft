/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write_special.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 13:32:20 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/08 13:37:59 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_constants.h"
#include "libft.h"
#include "conversion_interface.h"
#include <stddef.h>

size_t	ft_print_to_unsupported(char *to_write, const t_conversion *conv)
{
	(void)conv;
	ft_strcpy(to_write, UNSUPPORTED_CONVERSION_STRING);
	return (sizeof(UNSUPPORTED_CONVERSION_STRING));
}

size_t	ft_print_to_no_conversion(char *to_write, const t_conversion *conv)
{
	(void)conv;
	ft_strcpy(to_write, "%");
	return (ft_strlen("%"));
}
