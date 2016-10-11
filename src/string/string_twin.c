/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_twin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:30:58 by djean             #+#    #+#             */
/*   Updated: 2016/10/11 02:23:30 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"

/*
** Return a strict copy of the buffer '*b'
*/

t_string	*string_twin(t_string *b)
{
	t_string	*copy;

	copy = string_new(b->sizemax - 1);
	if (copy == NULL)
		return (NULL);
	copy->len = b->len;
	copy->iterator = b->iterator;
	ft_memcpy(copy->str, b->str, b->len);
	return (copy);
}
