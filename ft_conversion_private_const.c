/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_private_const.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 17:30:48 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/01 15:56:35 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"
#include "conv_len_interface.h"
#include "conv_write_interface.h"

size_t	ft_get_conv_len(const t_conversion *conv)
{
	return (g_print_len[conv->type](conv));
}

size_t	ft_get_conv_text_len(const t_conversion *conv)
{
	return (conv->specifier_length);
}

size_t	ft_write_conversion(char *to_write, const t_conversion *conv)
{
	return (g_print_to_test[conv->type](to_write, conv));
}

unsigned int	ft_arg_required(const void *conversion)
{
	return (((const t_conversion*)conversion)->arg_index);
}

unsigned int	get_modifier(const t_conversion *conversion)
{
	return (conversion->length_modifier);
}
