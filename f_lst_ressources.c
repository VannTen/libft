/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_lst_ressources.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 13:36:16 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/31 15:25:09 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_defs.h"
#include "custom_stddef.h"
#include <stdlib.h>

t_lst	*f_lstnew(void const *content)
{
	t_lst	*new;

	new = malloc(sizeof(t_lst));
	if (new != NULL)
	{
		new->content = (void*)content;
		new->next = NULL;
	}
	return (new);
}

void	f_lstdelone(t_lst *alst, t_destroy del)
{
	if (alst != NULL && del != NULL)
	{
		del(alst->content);
		alst->content = NULL;
		free(alst);
	}
}

void	f_lstdel(t_lst *alst, t_destroy del)
{
	t_lst	*to_del;

	if (alst != NULL && del != NULL)
	{
		while (alst != NULL)
		{
			to_del = alst;
			alst = alst->next;
			f_lstdelone(to_del, del);
		}
	}
}
