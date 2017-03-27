/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_len_special.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 17:25:17 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/27 15:42:36 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_interface.h"
#include "printf_constants.h"
#include "libft.h"

int	ft_printf_len_unsupported(const t_conversion *conv)
{
	(void)conv;
	return (ft_strlen(UNSUPPORTED_CONVERSION_STRING));
}

int	ft_printf_len_no_conversion(const t_conversion *conv)
{
	(void)conv;
	return (1);
}

int	ft_print_to_unsupported(char *to_write, const t_conversion *conv)
{
	(void)conv;
	ft_strcpy(to_write, UNSUPPORTED_CONVERSION_STRING);
	return (ft_strlen(UNSUPPORTED_CONVERSION_STRING));
}

int	ft_print_to_no_conversion(char *to_write, const t_conversion *conv)
{
	(void)conv;
	*to_write = CONVERSION_INDICATOR;
	return (1);
}
