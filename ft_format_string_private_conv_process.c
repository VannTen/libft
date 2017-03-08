/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_string_private_conv_process.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 14:37:15 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/08 14:39:30 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_string_defs.h"
#include "conversion_interface.h"
#include "libft.h"

static void		post_process_conv(void *conv)
{
	ft_post_process_conv((t_conversion*)conv);
}

void			ft_fmt_post_process(t_format_string *fmt)
{
	f_fifoiter(fmt->conversion_list, &post_process_conv);
}
