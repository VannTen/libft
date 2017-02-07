/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_variadic_args.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 12:48:04 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/07 14:11:11 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef enum	e_type
{
	UNKNOWN,
	INT,
	CHAR,
	SHORT,
	LONG,
	LONG_LONG,
	INTMAX,
	PTRDIFF,
	SIZE,
	QUAD,
	U_INT,
	U_CHAR,
	U_SHORT,
	U_LONG,
	U_LONG_LONG,
	U_INTMAX,
	U_PTRDIFF,
	U_SIZE,
	U_QUAD,
	PTR_INT,
	PTR_CHAR,
	PTR_SHORT,
	PTR_LONG,
	PTR_LONG_LONG,
	PTR_INTMAX,
	PTR_PTRDIFF,
	PTR_SIZE,
	PTR_QUAD
}				t_type;

typedef struct	s_var_arg
{
	void	*arg;
	t_type	type;
}				t_var_arg;
