/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_lstdelone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 21:40:35 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/03 16:38:39 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

void	f_lstdelone(t_lst *alst, void (*del)(void *content))
{
	if (alst != NULL && del != NULL)
	{
		del(alst->content);
		alst->content = NULL;
		free(alst);
	}
}
