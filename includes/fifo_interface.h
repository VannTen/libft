/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo_interface.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 13:00:00 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/31 15:05:36 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIFO_INTERFACE_H
# define FIFO_INTERFACE_H
# include "bool_interface.h"
# include "lst_interface.h"
# include "custom_stddef.h"

typedef struct s_fifo	t_fifo;

/*
** Ressources management
** Implementation file : f_fifo_ressources.c
*/

t_fifo				*f_fifo_create(void);
t_lst				*f_fifo_extract(t_fifo **fifo);
void				f_fifo_destroy(t_fifo **fifo, t_destroy del);

/*
** Add and take elems
** Implementation file : f_fifo_add_take.c
*/

t_fifo				*f_fifo_add(t_fifo *fifo, const void *content);
void				*f_fifo_take(t_fifo *fifo);

/*
** Relay of list functions
** Implementation files : f_fifo_lstrelay.c && f_fifo_lstrelay.c
*/

void				f_fifoiter(t_fifo *fifo, void (*f)(void*));
void				f_fifoiterarray(void *array, t_fifo *fifo,
		void (*apply)(void *lst_content, void *array));
size_t				f_fifomax(t_fifo *fifo, size_t (*get_max)(const void*));
int					f_fifosum_content(t_fifo *fifo,
		int (*add)(const void*));
int					f_fifodosum(t_fifo *fifo, int (*add)(void*));
void				*f_fifo_first_elem(const t_fifo *fifo);
size_t				f_fifoarray_end_early(void *array, t_fifo *fifo,
		size_t size, t_bool (*fifo_on_array)(const void *content, void *array));
void				f_fifomaparray(const void *src, void *dst, t_fifo *fifo,
		t_bool (*advance_arrays)(const void **src, void **dst, void *modifier));
void				*f_fifo_every_valid(t_fifo *fifo,
										t_bool (*test)(const void *content));

#endif
