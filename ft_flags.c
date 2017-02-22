/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 18:17:02 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/22 13:46:56 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags_defs.h"
#include "conversion_interface.h"
#include "bool.h"
#include <stdlib.h>

size_t			set_flags(const char *conversion_specifier, size_t index,
		t_conversion *convers_specs)
{
	while (set_one_flag(conversion_specifier, index, convers_specs))
		index++;
	return (index);
}
