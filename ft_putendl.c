/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 18:10:50 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/10 13:25:05 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(const char *s)
{
	char new_line;

	if (s != NULL)
	{
		new_line = '\n';
		write(STDOUT_FILENO, s, ft_strlen(s));
		write(STDOUT_FILENO, &new_line, 1);
	}
}
