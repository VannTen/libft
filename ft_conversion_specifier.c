/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_specifier.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 18:45:00 by mgautier          #+#    #+#             */
/*   Updated: 2017/01/29 17:23:09 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"
# include "libft.h"

void	set_arg(char **conversion_specifier, t_conversion *convers_specs,
				t_format_string *format);
{

}

void	set_flags(char **conversion_specifier, t_conversion *convers_specs)
{
	size_t	index;

	index = 0;
	while (**conversion_specifier != flags[index] && index < FLAGS_NBR)
		index++;
	if (index != FLAGS_NBR)
	{
		convers_specs->flags[index] = TRUE;
		return (TRUE)
	}
	else
		return (FALSE);
}
