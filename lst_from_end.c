/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_from_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:35:43 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/11 16:32:42 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_defs.h"

void	*lst_do_from_end(t_lst *lst,
		void *(*iter)(void *content, void *result_on_next))
{
	if (lst == NULL)
		return (NULL);
	else
		return (iter(lst->content, lst_do_from_end(lst->next, iter)));
}
