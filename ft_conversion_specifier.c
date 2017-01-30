/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_specifier.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 18:45:00 by mgautier          #+#    #+#             */
/*   Updated: 2017/01/30 10:51:09 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"
# include "libft.h"

void	set_arg(char **conversion_specifier, t_conversion *convers_specs,
				t_format_string *format);
{

}

void	set_one_flag(char **conversion_specifier, t_conversion *convers_specs)
{
	size_t	index;

	index = 0;
	while (index < FLAGS_NBR && **conversion_specifier != flags[index])
		index++;
	if (index != FLAGS_NBR)
	{
		convers_specs->flags[index] = TRUE;
		return (TRUE)
	}
	else
		return (FALSE);
}
