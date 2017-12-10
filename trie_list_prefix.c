/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_list_prefix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 17:51:49 by mgautier          #+#    #+#             */
/*   Updated: 2017/12/11 15:36:24 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trie_defs.h"
#include "trie_list_prefix_implem.h"

static void *va_get_trie_content(void const *trie, va_list args)
{
	t_lst			 **add_to;
	t_std_ope const	*f;
	size_t			depth;

	add_to = va_arg(args, t_lst**);
	f = va_arg(args, t_std_ope const*);
	depth = va_arg(args, size_t);
	return (get_trie_content(trie, add_to, f, depth));
}

static void	*get_trie_content(t_trie const *trie,
		t_lst **add_to,
		t_std_ope const *f,
		size_t const depth)
{
	if (trie->children == NULL)
		return (f->copy(trie->content.data));
	else if (f_lst_len(trie->children) == 1)
		return (get_trie_content(
					get_lst_elem(trie->children, 0),
					add_to,
					f,
					depth + 1));
	else
		return (resume_prefix_group(trie,
				add_to,
				f,
				depth + 1));
}

static void	*resume_prefix_group(
		t_trie const *trie,
		t_lst **lst,
		t_std_ope const *f,
		size_t const length)
{
	t_lst	*prefixes;

	prefixes = NULL;
	prefixes = f_lstmap_va(trie->children, va_get_trie_content, f->del,
			lst, f, length);
	if (prefixes != NULL)
	{
		f_lstpush(prefixes, lst);
		return (f->summarize(prefixes, length));
	}
	else
		return (NULL);
}

t_lst	*list_prefix_groups(
		t_trie const *trie,
		void *(*summarize)(t_lst *lst, size_t index),
		void *(*copy)(void const *),
		void (*del)(void **))
{
	t_lst		*prefix_group;
	void		*content;
	t_std_ope	f;

	f.del = del;
	f.copy = copy;
	f.summarize = summarize;
	prefix_group = NULL;
	content = resume_prefix_group(trie, &prefix_group, &f, 0);
	return (prefix_group);
}
