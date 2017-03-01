/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_string_private_const.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 16:35:42 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/01 15:18:44 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_string_defs.h"
#include "conversion_interface.h"
#include "libft.h"
#include <stddef.h>

size_t			ft_fmt_plain_text_len(const t_format_string *fmt)
{
	return (fmt->length - fmt->conversions_length);
}

static size_t	get_conv_len(const void *conversion)
{
	return (ft_get_conv_len((const t_conversion*)conversion));
}

size_t			ft_conversions_length(const t_format_string *fmt)
{
	return (f_fifosumsize_t_content(fmt->conversion_list, &get_conv_len));
}

size_t			ft_write_next_conversion(char *to_write, t_format_string *fmt)
{
	t_conversion	*conv;
	size_t			result_length;

	conv = f_fifo_take(fmt->conversion_list);
	result_length = ft_write_conversion(to_write, conv);
	return (result_length);
}

size_t			ft_get_current_conv_text_len(t_format_string *fmt)
{
	t_conversion *conv;

	conv = f_fifo_first_elem(fmt->conversion_list);
	return (ft_get_conv_text_len(conv));
}
