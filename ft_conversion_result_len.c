/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_result_len.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 10:29:12 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/28 16:37:45 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variadic_args_interface.h"
#include "conversion_interface.h"
#include "format_string_interface.h"
#include <stdlib.h>

size_t	ft_get_resulting_length(const t_format_string *fmt)
{
	size_t	result;

	result = ft_fmt_plain_text_len(fmt) + ft_conversions_length(fmt);
	return (result);
}

/*
typedef size_t (*mesure_length)(t_var_arg *arg, size_t index);
mesure_length	get_funct(t_conversion *conv);

mesure_length	get_funct(t_conversion *conv,)
{
	mesure_lentgh funct;
	funct = g_mesure_len[conv->conv_type];
	return (funct);
}


size_t			get_length(t_conversion *conv, t_var_arg *arg_list)
{
	size_t	result;

	result = get_arg_lenght(conv);
	result = adjust_precision(conv);
	result = count_flags(conv);
	result = adjust_field_width(conv);
}


size_t			ft_result_len_field_width(t_conversion *conv, t_var_arg *arg_list)
{
	size_t	arg_len;

	arg_len = level_2(conv, arg_list);
	if (arg_len < conv->field_width)
		result = conv->field_width;
	else
		result = arg_len;
	return (result);
}

size_t			ft_precision_result_len(t_conv, t_var_arg arg)
{
	size_t result;

	if (integer)
		precision_num;
	if (string)
		precision_string;
	if (floating_point);
		precision_float;
	return (result);
}

size_t			argument_length(t_conv, arg_list)
{
	D, I
		sign_integers_len(arg, &itoa_base_signed)
	O, U, X, X_MAJ
		(arg, &iota_base_signed, base)

size_t			level_two(t_conv, arg_list)
{
	size_t	result;


	return (result);
}
** get_size_functions
**
** need type argument
** need flags
** need conv_type
**
** flags that needs differentiated treatment
** -alternate form
** -signed
** -apostrophe
**
** common flags (do not influence length)
** -0 padding
** -left adjusted
**
** Precision and field width
**
** Levels :
** Level one ; common to all conversion
** Level two : common to conversion groups
** Level three : specific to conversion
**
** Level one
**
** field width
**
** Level two
**
** signed
** precision
** apostrophe
**
** Level three
**
** alternate form
** argument len
**
**
** Order of things
**
** Determine arg len/write (precision important here for strings)
** Determine precision length/write
** Determine flags lenght/write (apostrophe is with arg)
** Determine field_width
*/


