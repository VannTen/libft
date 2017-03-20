/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_private_valid_arg.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 14:31:08 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/20 10:44:03 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"

t_bool	ft_conversion_arg_is_valid(const t_conversion *conv)
{
	return (conv->is_valid);
}

t_bool	ft_precision_arg_is_valid(const t_conversion *conv)
{
	return (conv->precision.index_is_valid);
}

t_bool	ft_field_width_arg_is_valid(const t_conversion *conv)
{
	return (conv->precision.index_is_valid);
}
