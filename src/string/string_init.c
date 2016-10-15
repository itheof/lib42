/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:30:57 by djean             #+#    #+#             */
/*   Updated: 2016/10/15 15:46:59 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"

t_string	*string_init(t_string *s)
{
	return (string_init_with_capacity(s, STRING_INIT_SIZE));
}

t_string	*string_init_with_capacity(t_string *s, size_t capacity)
{
	s->capacity = capacity + 1;
	if (s->capacity < STRING_INIT_SIZE)
		s->capacity = STRING_INIT_SIZE;
	else if (!IS_POWER_OF_2(s->capacity))
		s->capacity = next_power_of_2(s->capacity);
	s->len = 0;
	if ((s->str = malloc(sizeof(char) * s->capacity)) == NULL)
		return (NULL);
	return (s);
}

void		string_shutdown(t_string *s)
{
	free(s->str);
}
