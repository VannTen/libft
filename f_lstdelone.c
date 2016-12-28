/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_lstdelone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 21:40:35 by mgautier          #+#    #+#             */
/*   Updated: 2016/12/28 13:14:08 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

void	f_lstdelone(t_lst **alst, void (*del)())
{
	if (alst != NULL && del != NULL)
	{
		del(&(*alst)->content);
		free(*alst);
		*alst = NULL;
	}
}
