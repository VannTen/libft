/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variadic_args_defs.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 10:32:31 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/20 17:26:45 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARIADIC_ARGS_DEFS_H
# define VARIADIC_ARGS_DEFS_H
# include "variadic_args_interface.h"
# include <stdarg.h>
# include <stddef.h>
# include <wchar.h>
# include <stdint.h>
# include <sys/types.h>

typedef enum					e_type
{
	UNKNOWN_TYPE,
	INT,
	LONG,
	LONG_LONG,
	CHAR,
	SHORT,
	INTMAX,
	PTRDIFF,
	SSIZE,
	QUAD,
	U_INT,
	U_LONG,
	U_LONG_LONG,
	U_CHAR,
	U_SHORT,
	U_INTMAX,
	U_PTRDIFF,
	SIZE,
	U_QUAD,
	PTR_INT,
	PTR_LONG,
	PTR_LONG_LONG,
	PTR_CHAR,
	PTR_SHORT,
	PTR_INTMAX,
	PTR_PTRDIFF,
	PTR_SIZE,
	PTR_QUAD,
	CARAC,
	WINT,
	STRING,
	WSTRING
}								t_type;

struct							s_var_arg
{
	union
	{
		int						t_int;
		char					t_char;
		short					t_short;
		long int				t_long_int;
		long long int			t_long_long_int;
		intmax_t				t_intmax_t;
		ptrdiff_t				t_ptrdiff_t;
		ssize_t					t_ssize_t;
		unsigned int			t_uint;
		unsigned char			t_uchar;
		unsigned short			t_ushort;
		unsigned long int		t_ulong_int;
		unsigned long long int	t_ulong_long_int;
		uintmax_t				t_uintmax_t;
		size_t					t_size_t;
		char					*t_ptr_char;
		short					*t_ptr_short;
		int						*t_ptr_int;
		long int				*t_ptr_long_int;
		long long int			*t_ptr_long_long_int;
		intmax_t				*t_ptr_intmax_t;
		ptrdiff_t				*t_ptr_ptrdiff_t;
		size_t					*t_ptr_size_t;
		wint_t					t_wint_t;
		wchar_t					*t_wstring;
	}							parameter;
	t_type						type;
};

#endif
