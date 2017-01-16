/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 13:07:34 by mgautier          #+#    #+#             */
/*   Updated: 2017/01/16 14:48:18 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Check every element of a list with the given function and return the
** number of elements who return TRUE
*/

unsigned int	ft_lstcheck(t_list *list, t_bool (*f)(t_list *elem))
{
	unsigned int	is_true;

	is_true = 0;
	while (list != NULL)
	{
		if (f(list))
			is_true++;
	}
	return (is_true);
}
