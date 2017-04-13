/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unix_usage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 15:48:03 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/13 19:11:35 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unix_usage_defs.h"
#include "printf.h"
#include "bool.h"
#include "libft.h"
#include <unistd.h>
#include <stddef.h>

static void	print_usage(const char *prog_name, const char *synopsis)
{
	ft_dprintf(STDERR_FILENO,
			"usage: %s [-%s] [file ...]\n", prog_name, synopsis);
}

static void	print_invalid_option(const char *prog_name, const char option)
{
	ft_dprintf(STDERR_FILENO, "%s: illegal option -- %c\n", prog_name, option);
}

static int	apply_one_opt(char opt_char, const char *synopsis,
		const t_apply_opt *apply_params, void *params)
{
	int index;

	index = 0;
	while (opt_char != synopsis[index] && synopsis[index] != '\0')
		index++;
	if (synopsis[index] != '\0')
		apply_params[index](params);
	else
		return (INVALID_OPTION);
	return (index);
}

static int	invalid(const char *prog, char opt_char,
		const char *synopsis)
{
	print_invalid_option(prog, opt_char);
	print_usage(prog, synopsis);
	return (USAGE_ERROR);
}

int			apply_cmdline_opt(const char *synopsis, const char **argv,
		void *params, const t_apply_opt *apply_params)
{
	int	opt_arg_nbr;
	int index;

	opt_arg_nbr = 1;
	while (argv[opt_arg_nbr] != NULL)
	{
		if (ft_strcmp("--", argv[opt_arg_nbr]) == 0)
			return (opt_arg_nbr + 1);
		else if (argv[opt_arg_nbr][0] != OPTION_CHARACTER
				|| argv[opt_arg_nbr][1] == '\0')
			return (opt_arg_nbr);
		index = 1;
		while (argv[opt_arg_nbr][index] != '\0')
		{
			if (INVALID_OPTION == apply_one_opt(argv[opt_arg_nbr][index],
						synopsis, apply_params, params))
				return (invalid(argv[0], argv[opt_arg_nbr][index], synopsis));
			else
				index++;
		}
		opt_arg_nbr++;
	}
	return (opt_arg_nbr);
}
