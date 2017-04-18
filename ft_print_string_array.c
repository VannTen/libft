/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string_array.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 17:54:22 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/18 18:44:33 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	ft_print_string_array(char **str_array, char sep)
{
	size_t	index;

	index = 0;
	while (str_array[index] != NULL)
	{
		ft_putstr(str_array[index]);
		ft_putchar(sep);
		index++;
	}
}
