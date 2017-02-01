/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argument_counter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 14:32:52 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/01 15:58:55 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	ft_max_arg_required(void *_conversion)
{
	t_conversion	*conversion;

	conversion = _conversion;
	if (conversion->arg_index > conversion->format_string->arg_count)
		conversion->format_string->arg_count = conversion->arg_index;
}

t_arg		*ft_argument_counter(t_format_string *format_string)
{
	t_arg	*arg_array;
	int		index;
	int		arg_nbr;

	format_string->arg_count = 0;
	index = 0;
	f_lstiter_content(format_string->conversion_list->begin_lst,
			&ft_max_arg_required);
	arg_nbr = format_string->arg_count;
	arg_array = malloc(sizeof(t_arg) * (arg_nbr + 1));
	if (arg_array != NULL)
	{
		while (index < arg_nbr)
		{
			arg_array[index].content = NULL;
			arg_array[index].type = NO_TYPE;
			index++;
		}
	}
	return (arg_array);
}

static void	ft_fill_args(void *_conversion)
{
	t_arg	*arg_array;
	size_t	index;

	arg_array = conversion->format_list->arguments;
	index = conversion->arg_index;

