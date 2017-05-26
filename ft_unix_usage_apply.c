/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unix_usage_apply.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 15:48:03 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/26 12:30:03 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unix_usage_defs.h"
#include "bool_interface.h"
#include "string_interface.h"
#include <stddef.h>

static int	apply_one_opt(size_t opt_char_index, const char **argv,
		const t_synopsis *synopsis, void *params)
{
	const char			opt_char = argv[0][opt_char_index];
	int					opt_return_status;

	opt_return_status = apply_no_arg_opt(opt_char, synopsis, params);
	if (opt_return_status == INVALID)
		opt_return_status =
			apply_arg_opt(opt_char_index, argv, synopsis, params);
	return (opt_return_status);
}

size_t		treat_one_cmdline_arg_opt(const t_synopsis *syn,
		const char **argv, void *param)
{
	size_t	index;
	int		option_return;

	index = 1;
	option_return = NOTHING_CONSUMED;
	while (argv[0][index] != '\0' && option_return == NOTHING_CONSUMED)
	{
		option_return = apply_one_opt(index, argv, syn, param);
		index++;
	}
	if (option_return == INVALID)
		print_option_error(syn->prog_name, argv[0][index], ILLEGAL_OPTION);
	return (option_return);
}

int			apply_cmdline_opt(const t_synopsis *synopsis, const char **argv,
		void *params)
{
	int					opt_arg_nbr;
	enum e_opt_return	opt_ret;

	opt_arg_nbr = 1;
	while (argv[opt_arg_nbr] != NULL)
	{
		if (ft_strcmp("--", argv[opt_arg_nbr]) == 0)
			return (opt_arg_nbr + 1);
		else if (argv[opt_arg_nbr][0] != OPTION_CHARACTER
				|| argv[opt_arg_nbr][1] == '\0')
			return (opt_arg_nbr);
		opt_ret =
			treat_one_cmdline_arg_opt(synopsis, argv + opt_arg_nbr, params);
		opt_arg_nbr++;
		if (opt_ret == INVALID)
		{
			synopsis->usage(synopsis->prog_name);
			return (USAGE_ERROR);
		}
		if (opt_ret == NEXT_CONSUMED)
			opt_arg_nbr++;
	}
	return (opt_arg_nbr);
}
