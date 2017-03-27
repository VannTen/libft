/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_len_special.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 17:25:17 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/27 17:07:59 by mgautier         ###   ########.fr       */
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

static int len_no_conv(const t_conversion *conv)
{
	(void)conv;
	return (1);
}

int	ft_printf_len_no_conversion(t_conversion *conv)
{
	return (strings_chars_length(conv, &len_no_conv, &len_no_conv));
}

int	ft_print_to_unsupported(char *to_write, const t_conversion *conv)
{
	(void)conv;
	ft_strcpy(to_write, UNSUPPORTED_CONVERSION_STRING);
	return (ft_strlen(UNSUPPORTED_CONVERSION_STRING));
}

static int	no_conv_writer(char *to_write, const t_conversion *conv)
{
	(void)conv;
	*to_write = CONVERSION_INDICATOR;
	return (1);
}
void	ft_print_to_no_conversion(char *to_write, const t_conversion *conv)
{
	write_whole_conv_strings_chars(to_write, conv,
			&no_conv_writer);
}
