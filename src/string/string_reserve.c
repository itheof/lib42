/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_reserve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 19:19:08 by crenault          #+#    #+#             */
/*   Updated: 2016/10/13 19:22:30 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"

t_string	*string_reserve(t_string *s, size_t additional)
{
	if (s->capacity - s->len < additional)
	{
		// TODO
	}
	return (s);
}
