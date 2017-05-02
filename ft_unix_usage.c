/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unix_usage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 10:59:42 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/02 14:55:53 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unix_usage_defs.h"

t_synopsis	*init_synopsis(const char *simple_opt_syn,
		t_apply_opt *simple_opt_apply,
		const char *param_opt_syn,
		t_apply_opt_param *param_opt_apply)
{
	static t_synopsis	syn;

	syn.options_char = simple_opt_syn;
	syn.options_param_char = param_opt_syn;
	syn.options = simple_opt_apply;
	syn.options_param = param_opt_apply;
	return (&syn);
}

void		add_opt_validator(t_synopsis *syn, t_bool (*is_valid)(int))
{
	syn->is_valid = is_valid;
}

void		add_usage(t_synopsis *syn, void (*usage)(void))
{
	syn->usage = usage;
}
