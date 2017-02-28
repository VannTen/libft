/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmt_result_length.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 17:27:57 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/28 17:28:26 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_string_interface.h"

size_t	ft_get_resulting_length(const t_format_string *fmt)
{
	size_t	result;

	result = ft_fmt_plain_text_len(fmt) + ft_conversions_length(fmt);
	return (result);
}
