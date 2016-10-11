/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:30:57 by djean             #+#    #+#             */
/*   Updated: 2016/10/11 02:23:53 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"

/*
** Create a new buffer
** The 'size' argument is the initial size for the string
** The allocated string  will be STRING_INIT_SIZE at the minimum
** or the next power of 2 if size is bigger than STRING_INIT_SIZE
*/

t_string	*string_new(size_t size)
{
	t_string	*new;

	new = ft_memalloc(sizeof(t_string));
	if (new == NULL)
		return (NULL);
	return (string_init(new, size));
}

/*
** Initialize an already existing buffer
** The rule for the size are the same than for string_new
*/

t_string	*string_init(t_string *b, size_t size)
{
	size_t	s;

	size += 1;
	if (size < STRING_INIT_SIZE)
		s = STRING_INIT_SIZE;
	else if (IS_POWER_OF_2(size))
		s = size;
	else
		s = next_power_of_2(size);
	b->sizemax = s;
	b->len = 0;
	b->iterator = 0;
	b->str = ft_memalloc(sizeof(char) * s);
	if (b->str == NULL)
		return (NULL);
	return (b);
}
