/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unix_files_interface.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 14:26:09 by mgautier          #+#    #+#             */
/*   Updated: 2017/06/01 15:09:10 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIX_FILES_INTERFACE_H
# define UNIX_FILES_INTERFACE_H

/*
** Testing file types
** Implementationf file : is_file.c
*/

t_bool	is_dir(const char *path);
t_bool	is_regfile(const char *path);

#endif
