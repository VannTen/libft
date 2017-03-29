/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_lstdel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 21:38:41 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/03 16:45:53 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "libft.h"
#include <stdlib.h>

void	f_lstdel(t_lst *alst, void (*del)(void *content))
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
