/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_string_private_get_length.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 13:15:48 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/20 13:19:48 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_string_defs.h"
#include "conversion_interface.h"
#include "libft.h"

static int	get_conv_len(const void *conversion)
{
	return (ft_get_conv_len((const t_conversion*)conversion));
}

int			ft_fmt_plain_text_len(const t_format_string *fmt)
{
	return (fmt->length - fmt->conversions_length);
}

int			ft_conversions_length(const t_format_string *fmt)
{
	return (f_fifosum_content(fmt->conversion_list, &get_conv_len));
}

int			ft_get_current_conv_text_len(t_format_string *fmt)
{
	t_conversion *conv;

	conv = f_fifo_first_elem(fmt->conversion_list);
	return (ft_get_conv_text_len(conv));
}
