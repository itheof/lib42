/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_shrink_to_fit.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 18:33:05 by crenault          #+#    #+#             */
/*   Updated: 2016/10/15 19:05:24 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"

t_string	*string_shrink_to_fit(t_string *s)
{
	size_t	capacity;

	if (s->len + 1 != s->capacity)
	{
		capacity = next_power_of_2(s->len + 1);
		if (capacity < STRING_INIT_SIZE)
			capacity = STRING_INIT_SIZE;
		if (capacity < s->capacity)
		{
			s->capacity = capacity;
			s->str = ft_realloc(s->str, capacity, s->len + 1);
			if (s->str == NULL)
				return (NULL);
		}
	}
	return (s);
}
