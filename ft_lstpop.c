/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_lstpop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:58:59 by mgautier          #+#    #+#             */
/*   Updated: 2016/12/14 17:16:43 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*f_lstpop(t_lst **first_link)
{
	t_lst	*pop;
	void	*content;

	pop = *first_link;
	if (pop != NULL)
		*first_link = (*first_link)->next;
	content = pop->content;
	free(pop);
	return (pop->content);
}
