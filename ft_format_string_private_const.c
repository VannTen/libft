/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_string_private_const.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 16:35:42 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/28 16:53:48 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_string_defs.h"
#include "libft.h"
#include <stddef.h>

size_t	ft_fmt_plain_text_len(const t_format_string *fmt)
{
	return (fmt->length - fmt->conversions_length);
}

size_t	ft_conversions_length(const t_format_string *fmt)
{
	return (f_fifosumsize_t_content(fmt->conversion_list, &ft_get_conv_len));
}
