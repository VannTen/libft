/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_private_integer_write.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 11:43:33 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/25 11:07:41 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"
#include "printf_constants.h"
#include "libft.h"

t_bool		has_alternate_form_hexa(const t_conversion *conv)
{
	return (((conv->type == X || conv->type == X_MAJ) &&
				has_no_null_value(conv->arg)) ||
			conv->type == P);
}
