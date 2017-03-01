/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_result_string.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 12:13:35 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/01 12:44:44 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_string_interface.h"
#include "printf_constants.h"

void	ft_write_result_string(const char *fmt, char *final_string,
		const t_format_string *fmt_tokens)
{
	size_t	index_fmt;
	size_t	index_final;

	index_fmt = 0;
	index_final = 0;
	while (fmt[index_fmt] != '\0')
	{
		if (fmt[index] == CONVERSION_INDICATOR)
		{
			index_final +=
				write_next_conversion(final_string + index_final, fmt_tokens);
			index_fmt+= get_current_conv_len(fmt_tokens);
		}
		else
		{
			final_string[index_final] = fmt[index_fmt];
			index_fmt++;
			index_final++;
		}
	}
}
