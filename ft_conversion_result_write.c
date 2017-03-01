/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_result_write.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 14:39:57 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/01 15:01:12 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conv_write_interface.h"
#include "conversion_interface.h"
#include "conv_len_interface.h"
#include "libft.h"

size_t	ft_print_to_unsupported( char *to_write, const t_conversion *conv)
{
	const char	str[] = UNSUPPORTED_CONVERSION_STRING;

	(void)conv;
	ft_strcpy(to_write, str);
	return (sizeof(str));
}

