/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_result_string.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 12:13:35 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/06 16:47:22 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_string_interface.h"
#include "printf_constants.h"
#include "bool.h"

t_bool	ft_write_next_conv(const char **fmt, char **final_string,
		t_conversion *conv)
{
	while (**fmt != CONVERSION_INDICATOR && **fmt != '\0')
	{
		**final_string = **fmt;
		*final_string += 1;
		*fmt += 1;
	}
	if (**fmt == CONVERSION_INDICATOR)
	{
		*fmt += ft_get_conv_text_len(conv);
		*final_string += ft_write_conversion(*final_string, conv);
		return (TRUE);
	}
	else
		return (FALSE);
}
