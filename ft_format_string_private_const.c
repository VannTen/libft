/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_string_private_const.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 16:35:42 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/10 14:42:19 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_string_defs.h"
#include "conversion_interface.h"
#include "libft.h"
#include <stddef.h>

int			ft_fmt_plain_text_len(const t_format_string *fmt)
{
	return (fmt->length - fmt->conversions_length);
}

static int	get_conv_len(const void *conversion)
{
	return (ft_get_conv_len((const t_conversion*)conversion));
}

int			ft_conversions_length(const t_format_string *fmt)
{
	return (f_fifosum_content(fmt->conversion_list, &get_conv_len));
}

static t_bool	write_to_next_conv(const void **fmt, void **final_string, void *conv)
{
	return (ft_write_next_conv((const char**)fmt, (char**)final_string,
			(t_conversion*)conv));
}

void			ft_write_result_string(const char *fmt_src, char *final_string,
		t_format_string *fmt)
{
	f_fifomaparray(fmt_src, final_string, fmt->conversion_list,
			&write_to_next_conv);
}

int			ft_get_current_conv_text_len(t_format_string *fmt)
{
	t_conversion *conv;

	conv = f_fifo_first_elem(fmt->conversion_list);
	return (ft_get_conv_text_len(conv));
}
