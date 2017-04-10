/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 18:10:50 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/10 13:25:45 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(const char *s, int fd)
{
	char new_line;

	if (s != NULL)
	{
		new_line = '\n';
		write(fd, s, ft_strlen(s));
		write(fd, &new_line, 1);
	}
}
