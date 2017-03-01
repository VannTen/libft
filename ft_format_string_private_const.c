/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_string_private_const.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 16:35:42 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/01 09:55:59 by mgautier         ###   ########.fr       */
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
