/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_exec_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 13:53:17 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/24 13:53:17 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_construct_interface.h"
#include "exec_interface.h"
#include "test_interface.h"
#include "libft.h"
#include <assert.h>

static t_bool	zero_left(void *construct, va_list args)
{
	if (get_remaining_symbols(construct) == 0)
	{
		(*(va_arg(args, size_t*)))++;
		return (TRUE);
	}
	else
		return (FALSE);
}

/*
** Aka : token, or empty_production
*/

static t_bool	test_no_len_prod(t_lst **exec_stack,
		size_t const last_count,
		size_t const final_last_count,
		size_t const *stack)
{
	t_exec_construct const *current;

	current = get_lst_elem(*exec_stack, 0);
	if (last_count == 1)
		return (stack[STACK_SIZE]
				== f_lst_len(*exec_stack) + stack[TERMINATED_CONSTRUCT]
				&& get_remaining_symbols(current) == final_last_count);
	else
		return (get_remaining_symbols(current) == last_count - 1);
}

static t_bool	test_len_prod_concrete(
		t_lst **stack,
		size_t const stack_size,
		size_t const prod_len,
		size_t const last_count)
{
	t_exec_construct const *current;
	t_exec_construct const *previous;

	current = get_lst_elem(*stack, 0);
	previous = get_lst_elem(*stack, 1);
	return (stack_size + 1 == f_lst_len(*stack)
			&& get_remaining_symbols(current) == prod_len
			&& get_remaining_symbols(previous) == last_count - 1);
}

static t_bool	test_len_prod_abstract(
		t_lst **stack,
		size_t const stack_size,
		size_t const prod_len,
		size_t const last_count)
{
	t_exec_construct const *current;
	t_exec_construct const *previous;

	current = get_lst_elem(*stack, 0);
	previous = get_lst_elem(*stack, 1);
	return (stack_size == f_lst_len(*stack)
			&& get_remaining_symbols(current) == prod_len + last_count - 1);
}

/*
** stack_size[1] is number of construct that shall be terminated after the
** transition
*/

static t_bool	test_one_construct_transition(
		t_lst **stack,
		t_exec const *functions,
		size_t const prod_len)
{
	size_t	stack_size[2];
	size_t	last_elem_count;
	size_t	final_last_elem_count;

	stack_size[STACK_SIZE] = f_lst_len(*stack);
	last_elem_count = get_remaining_symbols(get_lst_elem(*stack, 0));
	assert(stack_size[STACK_SIZE] >= 1 && last_elem_count > 0);
	stack_size[TERMINATED_CONSTRUCT] = 1;
	f_lstiterr_va(advance_list(*stack, 1),
			zero_left, &stack_size[TERMINATED_CONSTRUCT]);
	final_last_elem_count = stack_size[STACK_SIZE] > 1 ?
		get_remaining_symbols(get_lst_elem(*stack, stack_size[1])) : 0;
	put_sym_in_stack(stack, functions, prod_len);
	if (prod_len == 0)
		return (test_no_len_prod(stack, last_elem_count, final_last_elem_count,
					stack_size));
	else
		return ((functions != NULL ?
				test_len_prod_concrete :
				test_len_prod_abstract)
				(stack, stack_size[STACK_SIZE], prod_len, last_elem_count));
}

static t_bool	test_put_one_prod_in_stack(void)
{
	t_lst				*stack;
	t_exec const		functions[] = {
		{.give = give_expr, .create = create_expr},
		{.give = give_term, .create = create_term},
		{.give = give_factor, .create = create_factor},
		{.give = give_expr, .create = create_expr},
		{.give = NULL, .create = create_integer},
		{.create = NULL}
	};
	size_t const		prod_lengths[] = {3, 0, 1, 2, 0};
	size_t				index;
	t_exec_construct	*meta_construct;
	void				*final_result;

	stack = NULL;
	index = 0;
	meta_construct = create_init_meta_construct(&final_result);
	f_lstpush(meta_construct, &stack);
	while (index < ARRAY_LENGTH(functions) && stack != NULL
			&& test_one_construct_transition(
				&stack,
				&functions[index],
				prod_lengths[index]))
		index++;
	return (index == ARRAY_LENGTH(functions));
}

int	main(void)
{
	RET_TEST(test_put_one_prod_in_stack());
}
