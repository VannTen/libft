/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_construct_interface.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 18:54:54 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/23 18:54:54 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_CONSTRUCT_INTERFACE_H
# define EXEC_CONSTRUCT_INTERFACE_H
# include "exec_interface.h"

typedef struct s_exec_construct	t_exec_construct;

/*
** exec stack operation
** Perform operation need on the parser exec_stack to always have the instance
** of the symbol being currently parsed on top of it.
** Implemenation file : parser_exec_stack.c
*/

t_bool	one_less_symbol(t_lst **exec_stack);
t_bool	consume_token(
		void *token_from_lexer,
		t_lst **exec_stack,
		t_exec const *token_functions);
t_bool	put_one_prod_in_stack(
		t_lst **exec_stack,
		t_exec const *functions,
		size_t prod_len);

#endif
