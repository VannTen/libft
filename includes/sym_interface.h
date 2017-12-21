/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_interface.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 14:11:44 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/09 13:27:30 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAM_GEN_SYM_INTERFACE_H
# define GRAM_GEN_SYM_INTERFACE_H
# include "prods_interface.h"
# include <stdarg.h>
# include <stddef.h>
# define EMPTY_SYMBOL &g_empty_symbol

typedef struct s_symbol	t_symbol;

/*
** Ressources management
** Implementation file : sym_ressources.c
*/

t_symbol		*create_symbol(char const *name);
void			destroy_symbol(t_symbol **to_destroy);
void			iter_del_sym(void **to_del);
t_symbol		*derivate_new_sym(t_symbol const *src,
		char const *reason_why);

/*
** Setters
** Implementation file : sym_set.c
**
** add_prod : return NULL on succes, prod on failure.
*/

t_prod			*add_prod(t_symbol *sym, t_prod *prod);

/*
** Getters
** Take left recursive remove a t_prod object from sym and returns it, or return
** NULL if there is no left recursive production in the symbol.
** Implementation file : sym_get.c
*/

t_prod			*take_left_recursive(t_symbol *sym);
t_bool			has_left_recursion(t_symbol const *sym);
char const		*get_name(t_symbol const *sym);
size_t			get_prod_nb(t_symbol const *sym);

/*
** For debug
*/

t_prod const	*get_prod_number(t_symbol const *sym, size_t number);

/*
** Get sym properties
** Implementation file : sym_get_properties.c
*/

t_bool			has_empty_prod(t_symbol const *sym);
t_bool			has_symbol_in_first(
		t_symbol const *sym_first,
		t_symbol const *sym_is_here);

/*
** Printers
** Implementation file : sym_print.c
*/

void			print_sym_initializer(t_symbol const *sym, int fd);

/*
** Printers debug
** Implementation file : sym_print_back.c
*/

void			print_sym_back(t_symbol const *sym, int fd);

/*
** Parsing one symbol
** Implementation file : sym_parse.c
*/

t_symbol		*parse_symbol(char const *str_sym,
		t_fifo *sym_added,
		t_fifo *sym_pending);

/*
** Eliminate simple left recursion in a symbol.
** Implementation file : sym_transform_lrec.c
*/

t_symbol		*eliminate_left_recursion(t_symbol *sym);

/*
** Tool for eliminating indirect left recursion.
** Suppress reference to previous symbols by expanding them into their
** productions
** Implementation file : sym_transform_indirect_lrec.c
*/


t_bool			elim_indirect_left_recursion(
		t_symbol *sym,
		t_symbol const *sym_indir,
		t_bool dev_if_left);

/*
** Left factorize symbols to avoid necessity to have more than one token of
** lookahed when parsing
** Implementation file : sym_left_factor.c
*/

t_bool			left_factor_sym(t_symbol *sym, t_fifo *new_syms);
t_bool			is_result_of_left_factor(t_symbol const *sym);

/*
** Symbols equality (test purposes)
** Implementation file : sym_equality.c
**
** same_sym_parsed() : to be used in higher-order variadic functions.
*/

t_bool			symbol_are_identical(
		t_symbol const *sym,
		t_symbol const *sym_2);
t_bool			same_sym_parsed(const void *v_sym, va_list args);
t_bool			have_same_prods(t_symbol const *sym_1, t_symbol const *sym_2);

/*
** Symbols comparison (to compare different grammars)
** Implementation file : sym_cmp.c
*/

t_bool			sym_are_equ(t_symbol const *sym_1, t_symbol const *sym_2);
t_bool			prods_are_equ(t_symbol const *sym_1, t_symbol const *sym_2);

/*
** Sym valid names
** Implementation file : sym_valid.c
*/

t_bool			is_valid_sym_name_part(char c);
t_bool			is_valid_sym_name(char const *str);

/*
** Sym first set getters
** Implementation file : sym_get_first.c
*/

t_bool			has_symbol_in_first(
		t_symbol const *search_in, t_symbol const *to_find);

/*
** Sym empty_symbol
** Defintion of the global variable g_empty_symbol.
** It is an abstraction used to compute the first set when building the
** automaton. Since it is not really a grammar symbol (not included in the list
** of symbols) and always used, it seems logical to use a constant variable.
** Moreover, that abstraction is needed in several places, without necessary
** relations between them, which justify to use a global variable.
** Implementation file : sym_empty_symbol.c
*/

extern t_symbol const	g_empty_symbol;

/*
** Sym FIRST set computation
** Implementation file : sym_compute_first.c
*/

t_bool			compute_sym_first_set(t_symbol *sym, t_bool *sym_added);
t_lst const		*get_first_set(t_symbol const *sym);
t_bool			add_first_set_to_first_set(
		t_symbol const *sym,
		t_symbol *add_to,
		t_bool *sym_added);
t_bool			add_symbol_to_first_set(
		t_symbol const *sym,
		t_symbol *add_to,
		t_bool *sym_added);

/*
** (TESTING ONLY)
** Sym compute first test tools
** Functions used in test/sym_compute_first.c for testing of the section above.
** Implementation file : sym_compute_first_test_tools.c
*/

t_bool		compute_first_sets(t_symbol **syms, size_t nb_sym);
t_bool	check_first_sets(
		t_symbol **syms, t_lst **first_sets, size_t nb_sym);

/*
** Sym first set getters
** Implementation file : sym_get_first.c
*/

t_bool			has_symbol_in_first(
		t_symbol const *search_in, t_symbol const *to_find);
#endif
