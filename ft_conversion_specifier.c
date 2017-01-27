/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_specifier.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 18:45:00 by mgautier          #+#    #+#             */
/*   Updated: 2017/01/27 19:38:11 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"
# include "libft.h"

void	set_arg(char **conversion_specifier, t_conversion *convers_specs,
				t_format_string *format);
{
	int	argument_index;

	if (ft_is_positional(*conversion_specifier))
	{
		format->use_positionals = TRUE;
		convers_specs->arg_index = ft_atoi(conversion_specifier);
	}
	else
	{
		format->use_non_positionals = TRUE;
		format->arg_count++;
		convers_specs->arg_index = format->arg_count;
	}
	if (format->use_positionals && format->use_non_positionals)
		return (ERR_POSITIONAL_COHERENCE);
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


