/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_string_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 15:48:31 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/15 15:48:41 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_interface.h"
#include <stdlib.h>

char		**ft_free_string_array(char ***tab)
{
	char	**to_free;

	to_free = *tab;
	if (to_free != NULL)
	{
		while (*to_free != NULL)
		{
			ft_strdel(to_free);
			to_free++;
		}
		free(*tab);
		*tab = NULL;
	}
	return (*tab);
}
