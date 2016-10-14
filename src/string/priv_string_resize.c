/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   priv_string_resize.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:30:58 by djean             #+#    #+#             */
/*   Updated: 2016/10/14 16:27:51 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"

t_string	*priv_string_resize(t_string *s, size_t expand)
{
	void	*new;
	size_t	newsize;

	newsize = s->capacity * STRING_GROWTH_FACTOR;
	while (s->len + expand >= newsize)
		newsize *= STRING_GROWTH_FACTOR;
	new = ft_realloc(s->str, newsize, s->len);
	if (new == NULL)
		return (NULL);
	s->capacity = newsize;
	s->str = new;
	return (s);
}
