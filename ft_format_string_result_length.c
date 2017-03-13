/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_string_result_length.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 17:27:57 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/10 14:45:28 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_string_interface.h"

int	ft_get_resulting_length(const t_format_string *fmt)
{
	int	result;

	result = ft_fmt_plain_text_len(fmt) + ft_conversions_length(fmt);
	return (result);
}
