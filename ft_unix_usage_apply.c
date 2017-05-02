/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unix_usage_apply.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 15:48:03 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/02 14:28:19 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unix_usage_defs.h"
#include "printf.h"
#include "bool.h"
#include "libft.h"
#include <unistd.h>
#include <stddef.h>

static void	print_invalid_option(const char *prog_name, const char option)
{
	ft_dprintf(STDERR_FILENO, "%s: illegal option -- %c\n", prog_name, option);
}

static t_apply_opt select_no_param_opt(char opt_char,
		const t_synopsis *syn)
{
	size_t	index;

	index = 0;
	while (opt_char != syn->options_char[index]
			&& syn->options_char[index] != '\0')
		index++;
	if (syn->options_char[index] != '\0')
		return (*(syn->options + index));
	else
		return (NULL);
}

static t_apply_opt_param	select_param_opt(char opt_char,
		const t_synopsis *syn)
{
	size_t		index;

	index = 0;
	while (opt_char != syn->options_param_char[index]
			&& syn->options_param_char[index] != '\0')
		index++;
	if (syn->options_param_char[index] != '\0')
		return (*(syn->options_param + index));
	else
		return (NULL);
}

static int	apply_one_opt(size_t opt_char_index, const char **argv,
		const t_synopsis *synopsis, void *params)
{
	const char			opt_char = argv[0][opt_char_index];
	t_apply_opt			no_param_opt;
	t_apply_opt_param	param_opt;
	const char			*arg;
	t_bool				arg_opt_is_same_argv;

	no_param_opt = select_no_param_opt(opt_char, synopsis);
	if (no_param_opt != NULL)
	{
		if (!synopsis->is_valid(no_param_opt(params)))
			return (INVALID);
		else
			return (NOTHING_CONSUMED);
	}
	param_opt = select_param_opt(opt_char, synopsis);
	if (no_param_opt != NULL)
	{
		arg_opt_is_same_argv = argv[0][opt_char_index + 1] == '\0';
		arg =
			arg_opt_is_same_argv ?
			argv[1] :
			argv[0] + opt_char_index + 1;
		if (!synopsis->is_valid(no_param_opt(params)))
			return (INVALID);
		else
			return (arg_opt_is_same_argv ?
					NEXT_CONSUMED : CURRENT_CONSUMED);
	}
	print_invalid_option(synopsis->prog_name, opt_char);
	return (INVALID);
}

size_t		treat_one_cmdline_arg_opt(const t_synopsis *syn,
		const char **argv, void *param)
{
	size_t	index;
	int		option_return;

	index = 1;
	option_return = NOTHING_CONSUMED;
	while (argv[0][index] != '\0' && option_return == NOTHING_CONSUMED)
		option_return = apply_one_opt(index, argv, syn, param);
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
			synopsis->usage();
			return (USAGE_ERROR);
		}
		if (opt_ret == NEXT_CONSUMED)
			opt_arg_nbr++;
	}
	return (opt_arg_nbr);
}
