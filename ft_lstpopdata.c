/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpopdata.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 15:19:51 by mgautier          #+#    #+#             */
/*   Updated: 2016/12/07 15:25:26 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_lstpopdata(t_list **list)
{
	void	*content;
	t_list	*to_free;

	if (list == NULL || *list == NULL)
		return (NULL);
	content = (*list)->content;
	to_free = *list;
	*list = (*list)->next;
	free(to_free);
	return (content);
}
