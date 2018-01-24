/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_stack_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:08:14 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/24 14:08:14 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_construct_defs.h"

t_exec const	*get_construct_functions(t_exec_construct const *construct)
{
	return (construct->functions);
}

size_t			get_remaining_symbols(t_exec_construct const *construct)
{
	return (construct->remaining_symbols);
}
