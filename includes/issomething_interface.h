/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issomething_interface.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:25:30 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/23 17:30:41 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISSOMETHING_INTERFACE_H
# define ISSOMETHING_INTERFACE_H
# include "bool_interface.h"

/*
** Char checks
** Implementation file : function name.
*/

t_bool		ft_isalpha(int c);
t_bool		ft_isdigit(int c);
t_bool		ft_isalnum(int c);
t_bool		ft_isascii(int c);
t_bool		ft_isprint(int c);

#endif
