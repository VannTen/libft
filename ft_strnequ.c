/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 12:18:36 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/15 16:17:28 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_defs.h"
#include "bool_interface.h"
#include <stddef.h>

/*
** Check if two strings are equivqlent for the n first characters,
** using ft_strncmp.
*/

t_bool		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 != NULL && s2 != NULL
			&& ft_strncmp(s1, s2, n) == 0)
		return (TRUE);
	else
		return (FALSE);
}
