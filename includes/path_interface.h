/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_interface.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 11:13:58 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/15 11:54:27 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_INTERFACE_H
# define PATH_INTERFACE_H
# include "bool_interface.h"
# include <stddef.h>

/*
** Navigating in path strings (from one path componenent to another)
** Implementation file : path_tools.c
*/

size_t	get_previous_component(const char *path, size_t index_start);
size_t	path_comp_len(const char *path_elem);
t_bool	path_component_are_equal(const char *path1, const char *path2);
t_bool	is_root_component(const char *path, size_t index);
size_t	advance_nbr_path_comp(const char *path, size_t nbr);

/*
** Path canonicalization, as described in cd POSIX manual
** http://pubs.opengroup.org/onlinepubs/9699919799/
** Implementation file : canonical_path.c
*/

char	*canonize_path(char *path);

#endif
