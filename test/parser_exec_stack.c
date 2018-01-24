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

static t_bool	test_concrete_construct(
		t_lst **stack,
		size_t const *stack_size,
		size_t const prod_len,
		size_t const last_elem_count)
{
	if (prod_len == 0)
	{
		if (last_elem_count == 1)
			return (f_lst_len(*stack) == stack_size[0] - stack_size[1]);
		else
			return (f_lst_len(*stack) == stack_size[0]
					&& last_elem_count - 1
					== get_remaining_symbols(get_lst_elem(*stack, 0)));
	}
	else
		return (last_elem_count - 1
				== get_remaining_symbols(get_lst_elem(*stack, 1))
				&& f_lst_len(*stack) == stack_size[0] + 1
				&& get_remaining_symbols(get_lst_elem(*stack, 0))
				== prod_len - 1);
}

static t_bool	test_abstract_construct(
		t_lst **stack,
		size_t const *stack_size,
		size_t const prod_len,
		size_t const last_elem_count)
{
	if (last_elem_count == 1 && prod_len == 0)
		return (f_lst_len(*stack) == stack_size[0] - stack_size[1]);
	else
		return (get_remaining_symbols(get_lst_elem(*stack, 0))
					== last_elem_count + prod_len - 1);
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

	stack_size[0] = f_lst_len(*stack);
	last_elem_count = get_remaining_symbols(get_lst_elem(*stack, 0));
	assert(stack_size[0] >= 1 && last_elem_count > 0);
	stack_size[1] = 0;
	f_lstiterr_va(advance_list(*stack, 1), zero_left, &stack_size[1]);
	//stack_size[2] = get_remaining_symbols(get_lst_elem(*stack, stack_size[1]));
	put_sym_in_stack(stack, functions, prod_len);
	if (functions == NULL)
		return (test_abstract_construct(
					stack, stack_size, prod_len, last_elem_count));
	else
		return (test_concrete_construct(
					stack, stack_size, prod_len, last_elem_count));
}

static t_bool	test_put_one_prod_in_stack(void)
{
	t_lst			*stack;
	t_exec const	functions[] = {
		{.give = give_expr, .create = create_expr},
		{.give = give_term, .create = create_term},
		{.give = give_factor, .create = create_factor},
		{.give = give_expr, .create = create_expr},
		{.give = NULL, .create = create_integer},
		{.create = NULL}
	};
	size_t const	prod_lengths[] = {3, 2, 4, 0, 1};
	size_t			index;

	stack = NULL;
	index = 1;
	put_sym_in_stack(&stack, &functions[0], prod_lengths[0]);
	while (index < ARRAY_LENGTH(functions)
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
