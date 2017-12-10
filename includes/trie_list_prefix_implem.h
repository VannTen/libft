/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_list_prefix_implem.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 15:34:49 by mgautier          #+#    #+#             */
/*   Updated: 2017/12/11 15:35:41 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIE_LIST_PREFIX_IMPLEM_H
# define TRIE_LIST_PREFIX_IMPLEM_H
# include "trie_interface.h"
# include <stddef.h>

typedef struct	s_ste_ope
{
	void *(*summarize)(t_lst *lst, size_t index);
	void *(*copy)(const void *content);
	void (*del)(void **);
}				t_std_ope;

static void	*get_trie_content(t_trie const *trie,
		t_lst **add_to,
		t_std_ope const *f,
		size_t const depth);
static void	*resume_prefix_group(
		t_trie const *trie,
		t_lst **lst,
		t_std_ope const *f,
		size_t const length);

#endif
