/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string_array.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 17:54:22 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/15 16:28:08 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_interface.h"
#include "stdout_interface.h"
#include <stddef.h>

void	ft_print_string_array(char const *const *str_array, char sep)
{
	size_t	index;

	index = 0;
	if (str_array != NULL)
	{
		while (str_array[index] != NULL)
		{
			ft_putstr(str_array[index]);
			ft_putchar(sep);
			index++;
		}
	}
}
