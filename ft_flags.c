/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 18:17:02 by mgautier          #+#    #+#             */
/*   Updated: 2017/01/30 18:19:44 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_flags.h"

static t_bool	set_one_flag(const char *conversion_specifier, size_t index,
		t_conversion *convers_specs)
{
	size_t	index_flags;

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

size_t			set_flags(const char *conversion_specifier, size_t index,
		t_conversion *convers_specs)
{
	while (set_one_flag(conversion_specifier, index, convers_specs))
		index++;
	return (index);
}
