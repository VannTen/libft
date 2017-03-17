/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_private_is_conv_gen.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 11:03:18 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/17 11:05:11 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"
#include "bool.h"

t_bool	is_numeric(const t_conversion *conv)
{
	return (conv->type >= D && conv->type <= A_MAJ);
}
