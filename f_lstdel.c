/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_lstdel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 21:38:41 by mgautier          #+#    #+#             */
/*   Updated: 2016/12/28 13:13:47 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "libft.h"
#include <stdlib.h>

void	f_lstdel(t_lst **alst, void (*del)())
{
	t_lst	*new;
	t_lst	*to_del;

	if (alst != NULL && del != NULL)
	{
		new = *alst;
		while (new != NULL)
		{
			to_del = new;
			new = new->next;
			f_lstdelone(&to_del, del);
		}
		*alst = NULL;
	}
}
