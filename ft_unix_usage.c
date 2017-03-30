/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unix_usage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 15:48:03 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/30 18:01:34 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unix_usage_defs.h"
#include "bool.h"
#include <stddef.h>

static int	apply_one_opt(char opt_char, const char *synopsis,
		const t_apply_opt *apply_options, t_bool *options)
{
	int index;

	index = 0;
	while (opt_char != synopsis[index] && synopsis[index] != '\0')
		index++;
	if (synopsis[index] != '\0')
		apply_options[index](options);
	return (index);
}

int			apply_cmdline_opt(const char *synopsis, const char **argv,
		t_bool *options, const t_apply_opt *apply_options)
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
			index = 1;
			while (argv[opt_arg_nbr][index] != '\0')
			{
				apply_one_opt(argv[opt_arg_nbr][index], synopsis,
						apply_options, options);
				index++;
			}
		}
		opt_arg_nbr++;
	}
	return (opt_arg_nbr);
}
