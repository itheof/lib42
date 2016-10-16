/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_truncate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:30:58 by djean             #+#    #+#             */
/*   Updated: 2016/10/16 15:13:59 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"

ssize_t		array_truncate(t_array *a, size_t n)
{
	if (n > a->len)
		return (-1);
	a->len = n;
	return ((ssize_t)a->len);
}
