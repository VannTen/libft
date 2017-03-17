/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_private_set_final_length.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:40:11 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/17 12:19:15 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"
#include "variadic_args_interface.h"
#include "conv_len_interface.h"
#include "printf_constants.h"
#include "libft.h"

void	set_final_conversion_length(t_conversion *conv)
{
	int	no_field_width_result;

	settle_incompatibilities(conv);
	if (is_integer_conv(conv))
		no_field_width_result = set_integer_length(conv);
	else
		no_field_width_result = ft_get_len_conv(conv);
	if (conv->field_width.param.value <= no_field_width_result)
	{
		conv->field_width.param.value = no_field_width_result;
		conv->flags[NEGATIVE_FIELD_WIDTH] = FALSE;
	}
}
