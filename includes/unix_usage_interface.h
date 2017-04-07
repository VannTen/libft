/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unix_usage_interface.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:38:27 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/07 18:46:47 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIX_USAGE_INTERFACE_H
# define UNIX_USAGE_INTERFACE_H
# include "bool.h"

typedef	void (*t_apply_opt)(void *opt);

int			apply_cmdline_opt(const char *synopsis, const char **argv,
		void *params, const t_apply_opt *apply_options);
#endif
