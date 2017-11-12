/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_interface.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 13:29:22 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/11 16:50:48 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_INTERFACE_H
# define LST_INTERFACE_H
# include "custom_stddef.h"
# include "bool_interface.h"
# include <stddef.h>
# include <stdarg.h>

typedef struct s_lst	t_lst;

/*
** Ressources management
** Implementation file : f_lst_ressources.c
*/

t_lst				*f_lstnew(void const *content);
void				f_lstdelone(t_lst *alst, t_destroy del);
void				f_lstdel(t_lst **alst, t_destroy del);

/*
** Elems insertion and removal
** Implementation : f_lst_insert_remove.c
*/

t_lst				*f_add_end_lst(t_lst *last_link, const void *content);
t_lst				*f_add_end_lst_2(t_lst **last_link, const void *content);
t_lst				*f_lstpush(void const *content, t_lst **list);
void				*f_lstpop(t_lst **list);
t_bool				f_lstremoveif_one(t_lst **lst, int ref,
		int (*match)(const void *elem), t_destroy del);

/*
** Variadic function on list
** Those are intend to be used with function that take a void * + an arbitrary
** number of arguments, but there is no check if the argument list is correct.
** Implementation file : f_lst_variadic.c
*/

void				f_lstremoveif_va(t_lst **lst,
		t_bool (*match)(const void *elem, va_list),
		t_destroy content_dtor, ...);
void				f_lstiter_va(t_lst const *lst,
		void (*iter)(const void *elem, va_list),
		...);
void				f_lstiter_vas(t_lst const *lst,
		void (*iter)(const void *elem, va_list),
		va_list args);

/*
** List iterations
** Implementations file : f_lstiter.c
*/

void				f_lstiter(t_lst *lst, t_iter f);

/*
** List transformation
** Implementation file : f_lstmap.c
*/

t_lst				*f_lstmap(t_lst *lst, t_lst *(*f)(t_lst *elem));
t_lst				*f_lstmapi(t_lst *lst,
		t_lst *(*f)(t_lst *elem, unsigned int index));

/*
** List iterators where the passed function use multiples items in the list
** Implementation_file : lst_iter_multiple.c
**
*/

t_lst				*f_lst_mapinc_with_previous(
		t_lst *lst,
		void *(*iter)(void *i, void const *j),
		void *(*map)(void *i),
		t_destroy destroy);

/*
** List check elem
** Implementation file : f_lst_get_elem.c
*/

void				*f_lstsearch(const t_lst *list, const int ref,
		int (*match)(const void *elem));
void				*f_lst_first_elem(const t_lst *lst);

/*
** List array interactions
** Implementation file : f_lstarray.c
*/

size_t				f_lstarray_end_early(void *array, t_lst *lst, size_t size,
		t_bool (*put_lst_on_array)(const void *lst_content, void *array));
void				f_lstiterarray(void *array, t_lst *lst,
		void (*apply)(void *lst_content, void *array));
void				f_lstmaparray(const void *src, void *dst, t_lst *list,
		t_bool (*advance_arrays)(const void **src, void **dst, void *modifier));

/*
** List validation
** Implementation file : f_lst_valid.c
*/

void				*f_lst_every_valid(t_lst *list,
		t_bool (*test)(const void *content));

/*
** List count whole list
** Implementation file : f_lst_count.c
*/

unsigned int		f_lst_len(const t_lst *lst);
int					f_lstsum_content(t_lst *list, int (*f)(const void *));
int					f_lstdosum(t_lst *list, int (*f)(void *));
size_t				f_lstmax(t_lst *list, size_t (*get_max)(const void *));

#endif
