/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 15:04:09 by mgautier          #+#    #+#             */
/*   Updated: 2016/12/07 15:06:57 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Check if the list and the new node exists
** If so, give the pointer towards the previously-first node to the newly added
** and modify the pointer to the list towards that last
*/

t_list	ft_lstpush(t_list *alst, t_list *new)
{
	if (new != NULL)
		new->next = alst;
	return (new);
}
