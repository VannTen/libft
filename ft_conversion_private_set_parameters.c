/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_private_set_parameters.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 13:45:19 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/14 14:41:40 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"
#include "bool.h"

t_bool	set_one_flag(const char *conversion_specifier, int index,
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

void	set_conversion_spec_len(t_conversion *conv, int index)
{
	conv->specifier_length = index;
}
