/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_iter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 10:48:07 by djean             #+#    #+#             */
/*   Updated: 2016/10/11 22:19:11 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"

char	string_iterator(t_string *b)
{
	if (b->iterator >= b->len)
	{
		b->iterator = 0;
		return ('\0');
	}
	return (b->str[b->iterator++]);
}

void	string_iterator_prev(t_string *b)
{
	if (b->iterator > 0)
		b->iterator -= 1;
}

void	string_iterator_next(t_string *b)
{
	if (b->iterator < b->len)
		b->iterator += 1;
}

void	string_iterator_set(t_string *b, size_t index)
{
	b->iterator = index;
}
