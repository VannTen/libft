/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:14:05 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/14 18:04:43 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_array_defs.h"
#include "mem_interface.h"
#include "string_interface.h"
#include <stddef.h>

/*
** The function proceeds with a loop performing the folowing actions :
** advance until the current characther is different from the separator
** if the string is not finished : count one field
** advance until the separator is found or the string ends
** repeat
** That is use to count the number of split to be created ; the function then
** allocates an array of strings of the appropriate size.
** The same loop (only difference is that the number of field is used for end
** condition) is then used to allocates each split.
** If any allocation fail, all allocated memory (previous allocated splits and
** the containing array) are freed and their pointers set to NULL, and NULL is
** returned.
*/

static size_t	ft_strsublen(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	return (len);
}

static size_t	ft_nb_field(char const *s, char c)
{
	size_t	index;
	size_t	nb_field;

	index = 0;
	nb_field = 0;
	while (s[index] != '\0')
	{
		while (s[index] == c)
			index++;
		if (s[index] != '\0')
		{
			nb_field++;
			while ((s[index] != c) && (s[index] != '\0'))
				index++;
		}
	}
	return (nb_field);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	index;
	size_t	nb_field;
	size_t	field_n;
	char	**strsplit;

	if (s == NULL)
		return (NULL);
	nb_field = ft_nb_field(s, c);
	strsplit = (char**)ft_memalloc(sizeof(char*) * (nb_field + 1));
	if (strsplit == NULL)
		return (strsplit);
	field_n = 0;
	index = 0;
	while (field_n < nb_field)
	{
		while (s[index] == c)
			index++;
		strsplit[field_n] = ft_strsub(s, index, ft_strsublen((s + index), c));
		if (strsplit[field_n] == NULL)
			return (ft_free_string_array(&strsplit));
		while ((s[index] != c) && (s[index] != '\0'))
			index++;
		field_n++;
	}
	return (strsplit);
}

char		*ft_va_strstrip(char const *str, va_list args)
{
	return (ft_strip(str, va_arg(args, const char*)));
}

char		**ft_strsplit_and(
		char const *str,
		char const c,
		char *(*map)(const char*, va_list),
		...)
{
	char	**str_arr;
	char	**res_str_arr;
	va_list	args;

	str_arr = ft_strsplit(str, c);
	va_start(args, map);
	res_str_arr = ft_str_array_map_vas((char const *const*)str_arr, map, args);
	va_end(args);
	ft_free_string_array(&str_arr);
	return (res_str_arr);
}
