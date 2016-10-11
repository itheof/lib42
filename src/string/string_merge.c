/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_merge.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:30:57 by djean             #+#    #+#             */
/*   Updated: 2016/10/11 02:21:29 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"

/*
** Create a new buffer, resulting in the merge of '*b1' and '*b2'
*/

t_string	*string_merge(t_string *b1, t_string *b2)
{
	t_string	*new;
	size_t		size;

	size = b1->len + b2->len;
	new = string_new(size);
	if (new == NULL)
		return (NULL);
	new->len = b1->len + b2->len;
	ft_memcpy(new->str, b1->str, b1->len);
	ft_memcpy(new->str + b1->len, b2->str, b2->len);
	return (new);
}
