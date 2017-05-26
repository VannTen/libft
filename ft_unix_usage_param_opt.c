/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unix_usage_param_opt.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 16:43:52 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/26 12:30:01 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unix_usage_defs.h"
#include <stddef.h>

static t_apply_opt			select_no_param_opt(
		char opt_char,
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

static t_apply_opt_param	select_param_opt(
		char opt_char,
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

int							apply_arg_opt(
		const size_t opt_char_index,
		const char **argv,
		const t_synopsis *syn,
		void *params)
{
	t_bool				arg_opt_is_same_argv;
	t_apply_opt_param	apply_opt;
	const char			*arg;

	if (syn->options_param != NULL)
	{
		apply_opt = select_param_opt(argv[0][opt_char_index], syn);
		if (apply_opt != NULL)
		{
			arg_opt_is_same_argv = argv[0][opt_char_index + 1] != '\0';
			if (arg_opt_is_same_argv)
				arg = argv[0] + opt_char_index + 1;
			else
				arg = argv[1];
			if (arg == NULL)
			{
				print_option_error(syn->prog_name,
						argv[0][opt_char_index], REQ_ARG);
				return (INVALID);
			}
			if (syn->is_valid(apply_opt(params, arg)))
				return (arg_opt_is_same_argv ? NEXT_CONSUMED : CURRENT_CONSUMED);
		}
	}
	return (INVALID);
}

int							apply_no_arg_opt(
		const char opt_char,
		const t_synopsis *syn,
		void *params)
{
	t_apply_opt	apply_opt;

	if (syn->options != NULL)
	{
		apply_opt = select_no_param_opt(opt_char, syn);
		if (apply_opt != NULL && syn->is_valid(apply_opt(params)))
			return (NOTHING_CONSUMED);
	}
	return (INVALID);
}
