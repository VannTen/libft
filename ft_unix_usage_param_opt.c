/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unix_usage_param_opt.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 16:43:52 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/02 09:49:19 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unix_usage_defs.h"
#include <stddef.h>

t_apply_opt_param	select_option(const char *synopsis,
		char opt, const t_apply_opt_param *options)
{
	size_t	index;

	index = 0;
	while (synopsis[index] != '\0' && synopsis[index] != opt)
		index++;
	if (synopsis[index] == '\0')
		return (NULL);
	else
		return (options[index]);
}

int						apply_parameters_options(const char *synopsis,
		const char **param_opt, void *parameters,
		const t_apply_opt_param *apply_options)
{
	int					opt_arg_nbr;
	t_apply_opt_param	apply_opt;

	opt_arg_nbr = 0;
	while (param_opt[opt_arg_nbr] != NULL
			&& param_opt[opt_arg_nbr][0] == OPTION_CHARACTER)
	{
		apply_opt =
			select_option(synopsis, param_opt[opt_arg_nbr][1], apply_options);
		if (apply_opt != NULL)
			apply_opt(parameters, param_opt[opt_arg_nbr]);
		opt_arg_nbr++;
	}
	return (opt_arg_nbr);
}
