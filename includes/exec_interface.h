/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_interface.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:22:07 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/23 17:22:07 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_INTERFACE_H
# define EXEC_INTERFACE_H

typedef	void *(*t_create_construct)(void *lex_value);
typedef	void (*t_give_construct)(void *construct, void *sub_construct);

typedef struct s_exec	t_exec;

struct	s_exec
{
	char const			*name;
	t_create_construct	create;
	t_give_construct	give;
};

#endif
