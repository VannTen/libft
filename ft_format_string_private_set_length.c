/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_string_private_set_length.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:28:21 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/04 13:43:22 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_string_defs.h"
#include "conversion_interface.h"
#include "libft.h"

static void	set_conv_res_length(void *conv)
{
	set_conversion_result_length((t_conversion*)conv);
}

void	ft_compute_convs_length(t_format_string *fmt)
{
	f_fifoiter(fmt->conversion_list, &set_conv_res_length);
}
