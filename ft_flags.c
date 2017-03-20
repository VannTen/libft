/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 18:17:02 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/20 13:36:04 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags_defs.h"
#include "conversion_defs.h"
#include "variadic_args_interface.h"
#include "printf_constants.h"
#include "bool.h"
#include "libft.h"
#include <stdlib.h>

static t_bool	set_one_flag(const char *conversion_specifier, int index,
		t_conversion *convers_specs)
{
	enum e_flags		index_flags;
	static const char	flags[] = "#0- +'";

	index_flags = 0;
	while (index_flags < FLAGS_NBR
			&& conversion_specifier[index] != flags[index_flags])
		index_flags++;
	if (index_flags != FLAGS_NBR)
	{
		convers_specs->flags[index_flags] = TRUE;
		return (TRUE);
	}
	else
		return (FALSE);
}

int				set_flags(const char *conversion_specifier,
		t_conversion *convers_specs)
{
	int	index;

	index = 0;
	while (set_one_flag(conversion_specifier, index, convers_specs))
		index++;
	return (index);
}

static int		ft_write_alternate_form(char *to_write,
		const t_conversion *conv)
{
	int	flags_len;

	flags_len = 0;
	if (conv->flags[ALTERNATE_FORM])
	{
		if ((conv->type == X || conv->type == X_MAJ)
				&& has_no_null_value(conv->arg))
		{
			ft_strcpy(to_write, conv->type == X ?
					HEXA_ALTERNATE_FORM : HEXA_MAJ_ALTERNATE_FORM);
			flags_len += ft_strlen(HEXA_ALTERNATE_FORM);
		}
		else if (conv->type == O)
		{
			ft_strcpy(to_write, OCTAL_ALTERNATE_FORM);
			flags_len += ft_strlen(OCTAL_ALTERNATE_FORM);
		}
	}
	return (flags_len);
}

int				ft_write_flags(char *to_write, const t_conversion *conv)
{
	int	flags_len;

	flags_len = ft_write_alternate_form(to_write, conv);
	if (conv->flags[ALWAYS_SIGN] && is_signed_positive(conv->arg))
	{
		to_write[flags_len] = '+';
		flags_len++;
	}
	else if (conv->flags[BLANK] && is_signed_positive(conv->arg))
	{
		to_write[flags_len] = ' ';
		flags_len++;
	}
	return (flags_len);
}

int				ft_flags_len(const t_conversion *conv)
{
	int	flags_len;

	flags_len = 0;
	if (conv->flags[ALTERNATE_FORM])
	{
		if ((conv->type == X || conv->type == X_MAJ)
				&& has_no_null_value(conv->arg))
			flags_len += ft_strlen(HEXA_ALTERNATE_FORM);
		else if (conv->type == O)
			flags_len += ft_strlen(OCTAL_ALTERNATE_FORM);
	}
	if (conv->flags[ALWAYS_SIGN] && is_signed_positive(conv->arg))
		flags_len++;
	else if (conv->flags[BLANK] && is_signed_positive(conv->arg))
		flags_len++;
	return (flags_len);
}
