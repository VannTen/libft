/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_private_is_conv.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 12:11:51 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/24 16:55:58 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"
#include "bool.h"

t_bool			is_signed_integer_conv(const t_conversion *conversion)
{
	return (conversion->type <= I ? TRUE : FALSE);
}

t_bool			is_unsigned_integer_conv(const t_conversion *conversion)
{
	return (conversion->type <= X_MAJ && conversion->type >= O ? TRUE : FALSE);
}

t_bool			is_ptr_conv(const t_conversion *conversion)
{
	return (conversion->type == N ? TRUE : FALSE);
}

t_bool			is_string_conv(const t_conversion *conversion)
{
	return (conversion->type == S ? TRUE : FALSE);
}
