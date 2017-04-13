/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gen_strdel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:22:36 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/13 19:59:19 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function is useful to use ft_strdel with generic function using a
** function pointer of the form (*del)(void*) (such as a list destructor)
*/

void	ft_gen_strdel(void **str)
{
	ft_strdel((char**)str);
}
