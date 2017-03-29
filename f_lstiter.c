/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_lstiter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 10:41:10 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/01 12:06:41 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Check if the function is valid (first link is checked by the first iteration
** of the while) and initialize with the first link of the list
** Then, until end of the loop (link pointing to NULL) :
** stock the current link
** move to the next
** apply the function on the stocked link
*/

void	f_lstiter(t_lst *lst, void (*f)(t_lst *elem))
{
	t_lst	*new;
	t_lst	*to_iter;

	if (f != NULL)
	{
		new = lst;
		while (new != NULL)
		{
			to_iter = new;
			new = new->next;
			f(to_iter);
		}
	}
}

void	f_lstiter_content(t_lst *lst, void (*f)(void *content))
{
	t_lst	*new;
	t_lst	*to_iter;

	if (f != NULL)
	{
		new = lst;
		while (new != NULL)
		{
			to_iter = new;
			new = new->next;
			f(to_iter->content);
		}
	}
}
