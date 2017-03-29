/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unix_usage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 15:48:03 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/29 17:09:02 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unix_usage_defs.h"
#include "bool.h"
#include <stddef.h>

int		apply_one_opt(char opt_char, const char *synopsis,
		t_apply_opt *apply_options, t_bool *options)
{
	int index;

	index = 0;
	while (opt_char != synopsis[index] && synopsis[index] != '\0')
		index++;
	if (synopsis[index] != '\0')
		apply_options[index](options);
	return (index);
}

int		apply_cmdline_opt(const char *synopsis, char **argv, t_bool
		*options, t_apply_opt *apply_options)
{
	int	opt_arg_nbr;
	int index;

	opt_arg_nbr = 0;
	while (argv[opt_arg_nbr] != NULL)
	{
		if (argv[opt_arg_nbr][0] != OPTION_CHARACTER
				|| argv[opt_arg_nbr][1] == '\0')
			break ;
		else
		{
			index = 0;
			while (argv[opt_arg_nbr][index] != '\0')
			{
				apply_one_opt(argv[opt_arg_nbr][index], synopsis,
						apply_options, options);
			}
		}
		opt_arg_nbr++;
	}
	return (opt_arg_nbr);
}
/*
t_bool	*unix_usage(const char *synopsis, int option_nbr,
		int argc, const char **argv)
{

}
*/
