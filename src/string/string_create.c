/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:30:57 by djean             #+#    #+#             */
/*   Updated: 2016/10/15 14:37:32 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"

t_string	*string_create(void)
{
	t_string	*s;

	s = malloc(sizeof(t_string));
	if (s == NULL)
		return (NULL);
	return (string_init(s));
}

t_string	*string_create_with_capacity(size_t capacity)
{
	t_string	*s;

	s = malloc(sizeof(t_string));
	if (s == NULL)
		return (NULL);
	return (string_init_with_capacity(s, capacity));
}

void		string_destroy(t_string *s)
{
	free(s->str);
	free(s);
}
