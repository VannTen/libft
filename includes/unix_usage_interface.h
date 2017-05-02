/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unix_usage_interface.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:38:27 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/02 09:50:18 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIX_USAGE_INTERFACE_H
# define UNIX_USAGE_INTERFACE_H
# include "bool.h"
# define USAGE_ERROR -1

typedef struct s_synopsis	t_synopsis;
typedef	void	(*t_apply_opt)(void *opt);
typedef void	(*t_apply_opt_param)(void *parameters, const char *arg);

int			apply_cmdline_opt(const char *synopsis, const char **argv,
		void *params, const t_apply_opt *apply_options);
int			apply_parameters_options(const char *synopsis,
		const char **param_opt, void *parameters,
		const t_apply_opt_param *apply_options);
#endif
