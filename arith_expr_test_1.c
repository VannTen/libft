/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arith_expr_test_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 13:12:54 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/22 13:12:54 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_interface.h"
#include <stdlib.h>

void	*create_expr(__attribute__((unused))void *no_val)
{
	int	*expr;

	expr = malloc(sizeof(*expr));
	if (expr != NULL)
		*expr = 0;
	return (expr);
}

void	give_expr(void *v_expr, void *to_give)
{
	int *expr;
	int	*term;

	expr = v_expr;
	term = to_give;
	*expr = *expr + *term;
	free(term);
}

void	*create_term(__attribute__((unused))void *no_val)
{
	int	*term;

	term = malloc(sizeof(*term));
	if (term != NULL)
		*term = 0;
	return (term);
}

void	give_term(void *v_term, void *to_give)
{
	int	*term;
	int	*factor;

	term = v_term;
	factor = to_give;
	*term = *term * *factor;
	free(factor);
}

void	*create_factor(__attribute__((unused))void *no_val)
{
	int	*factor;

	factor = malloc(sizeof(*factor));
	if (factor != NULL)
		*factor = 0;
	return (factor);
}
