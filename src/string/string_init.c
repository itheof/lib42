/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:30:57 by djean             #+#    #+#             */
/*   Updated: 2016/10/11 23:34:15 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"

/*
** Initialize an already existing buffer
** The rule for the size are the same than for string_new
*/

t_string	*string_init(t_string *s, size_t size)
{
	size += 1;
	if (size < STRING_INIT_SIZE)
		size = STRING_INIT_SIZE;
	else if (!IS_POWER_OF_2(size))
		size = next_power_of_2(size);
	s->sizemax = size;
	s->len = 0;
	s->iterator = 0;
	if ((s->str = malloc(sizeof(char) * size)) == NULL)
		return (NULL);
	return (s);
}
