/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unix_usage_apply.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 15:48:03 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/03 16:47:37 by mgautier         ###   ########.fr       */
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

static int	apply_arg_opt(const size_t opt_char_index, const char **argv,
		const t_synopsis *syn, void *params)
{
	t_bool				arg_opt_is_same_argv;
	t_apply_opt_param	apply_opt;
	const char			*arg;

	apply_opt = select_param_opt(argv[0][opt_char_index], syn);
	if (apply_opt != NULL)
	{
		arg_opt_is_same_argv = argv[0][opt_char_index + 1] == '\0';
		if (arg_opt_is_same_argv)
			arg = argv[1];
		else
			arg = argv[0] + opt_char_index + 1;
		if (syn->is_valid(apply_opt(params, arg)))
			return (arg_opt_is_same_argv ? NEXT_CONSUMED : CURRENT_CONSUMED);
	}
	return (INVALID);
}

static int	apply_no_arg_opt(const char opt_char,
		const t_synopsis *syn, void *params)
{
	t_apply_opt	apply_opt;

	apply_opt = select_no_param_opt(opt_char, syn);
	if (apply_opt != NULL && syn->is_valid(apply_opt(params)))
		return (NOTHING_CONSUMED);
	return (INVALID);
}

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
		option_return = apply_one_opt(index, argv, syn, param);
	if (option_return == INVALID)
		print_invalid_option(syn->prog_name, argv[0][index]);
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
