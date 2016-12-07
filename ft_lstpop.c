/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:58:59 by mgautier          #+#    #+#             */
/*   Updated: 2016/12/07 15:03:11 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_list	*ft_lstpop(t_list **first_link)
{
	t_list	pop;

	pop = *first_link;
	if (pop != NULL)
		*first_link = first_link->next;
	return (NULL);
}
