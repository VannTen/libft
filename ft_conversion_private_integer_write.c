/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_private_integer_write.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 11:43:33 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/21 11:18:30 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"
#include "printf_constants.h"
#include "libft.h"

static int	write_signedness(char *to_write, const t_conversion *conv)
{
	int index;

	index = 0;
	if (is_signed_negative(conv->arg))
	{
		*to_write = '-';
		index++;
	}
	else if (is_signed_positive(conv->arg))
	{
		if (conv->flags[ALWAYS_SIGN])
		{
			*to_write = '+';
			index++;
		}
		else if (conv->flags[BLANK])
		{
			*to_write = ' ';
			index++;
		}
	}
	return (index);
}

t_bool		has_alternate_form_hexa(const t_conversion *conv)
{
	return (((conv->type == X || conv->type == X_MAJ) &&
				has_no_null_value(conv->arg)) ||
			conv->type == P);
}

static int	write_alternate_form(char *to_write, const t_conversion *conv)
{
	int	alternate_form_len;

	alternate_form_len = 0;
	if (conv->flags[ALTERNATE_FORM])
	{
		if (has_alternate_form_hexa(conv))
		{
			ft_strcpy(to_write, conv->type == X_MAJ ?
					HEXA_MAJ_ALTERNATE_FORM : HEXA_ALTERNATE_FORM);
			alternate_form_len += ft_strlen(HEXA_ALTERNATE_FORM);
		}
		else if (conv->type == O)
		{
			ft_strcpy(to_write, OCTAL_ALTERNATE_FORM);
			alternate_form_len += ft_strlen(OCTAL_ALTERNATE_FORM);
		}
	}
	return (alternate_form_len);
}

int			ft_write_integer_conv(char *to_write, const t_conversion *conv)
{
	int	index;

	index = 0;
	if (is_signed_integer_conv(conv))
		index += write_signedness(to_write, conv);
	else
		index += write_alternate_form(to_write, conv);
	return (index);
}
