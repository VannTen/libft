/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_interface.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 13:29:22 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/17 14:31:32 by mgautier         ###   ########.fr       */
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
** Operations on several lists
** Implementation file : lst_several.c
*/

t_lst				*join_lst(t_lst *lst_1, t_lst const *to_join);
t_bool				lst_equ(t_lst const *lst1, t_lst const *lst2,
		t_bool (*equ)(void const*, void const*));

/*
** Insert or delete on tail of the list
** Implementation file : f_lst_insert_remove_end.c
*/

void				*f_pushend_lst(t_lst **lst, void *content);
void				*f_popend_lst(t_lst	**lst);

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
void				f_lstiteri_va(t_lst const *lst,
		void (*iter)(const void *elem, size_t index, va_list),
		...);
void				f_lstiteri_vas(t_lst const *lst,
		void (*iter)(const void *elem, size_t index, va_list),
		va_list args);

/*
** Take elem of list
** These function take out of the list elems that match the given function.
** Implementation file : lst_take_elems.c
*/

void				*f_lsttakeone_if_vas(
		t_lst **lst,
		t_bool truth,
		t_bool (*match)(void const *elem, va_list args),
		va_list args);
void				*f_lsttakeone_if_va(
		t_lst **lst,
		t_bool truth,
		t_bool (*match)(void const *elem, va_list args),
		...);
t_lst				*f_split_lst_vas(
		t_lst **lst,
		t_bool truth,
		t_bool (*match)(void const *elem, va_list args),
		va_list args);
t_lst				*f_split_lst_va(
		t_lst **lst,
		t_bool truth,
		t_bool (*match)(void const *elem, va_list args),
		...);

/*
** Variadic functions on list, with error reports.
** Same as above, but used with function which can fail, (memory allocation,
** etc). The list function shall report the error to its caller, so it will stop
** at the first error found.
** Able to modify content.
** Implementation file : f_lst_variadic_err.c
*/

t_bool				f_lstiterr_vas(
		t_lst *lst,
		t_bool (*iter)(void *elem, va_list),
		va_list args);
t_bool				f_lstiterr_va(
		t_lst *lst,
		t_bool (*iter)(void *elem, va_list),
		...);

/*
** List iterations
** Implementations file : f_lstiter.c
*/

void				f_lstiter(t_lst *lst, t_iter f);

/*
** List transformation
** Implementation file : f_lstmap.c
*/

t_lst				*f_lstmap(
		t_lst const *lst,
		void *(*f)(void const *elem),
		t_destroy del);
t_lst				*f_lstmapi(
		t_lst const *lst,
		void *(*f)(void const *elem, unsigned int index),
		t_destroy del);
t_lst	*f_lstmap_vas(
		t_lst const *lst,
		void *(*change)(void const*, va_list args),
		t_destroy destroy,
		va_list args);
t_lst	*f_lstmap_va(
		t_lst const *lst,
		void *(*change)(void const*, va_list args),
		t_destroy destroy,
		...);

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
t_lst				*advance_list(const t_lst *lst, size_t n_times);
t_lst				*lst_last_link(t_lst *lst);

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

void				*f_lst_every_valid(t_lst const *list,
		t_bool (*test)(const void *content));
void				*f_lst_every_valid_va(t_lst const *list,
		t_bool valid_result,
		t_bool (*test)(const void *content, va_list args), ...);
void				*f_lst_every_valid_vas(t_lst const *list,
		t_bool valid_result,
		t_bool (*test)(const void *content, va_list args), va_list args);

/*
** List count whole list
** Implementation file : f_lst_count.c
*/

unsigned int		f_lst_len(const t_lst *lst);
int					f_lstsum_content(t_lst *list, int (*f)(const void *));
int					f_lstdosum(t_lst *list, int (*f)(void *));
size_t				f_lstmax(t_lst *list, size_t (*get_max)(const void *));

#endif
