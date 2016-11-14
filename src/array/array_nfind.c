/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_nfind.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 13:33:47 by tvallee           #+#    #+#             */
/*   Updated: 2016/11/14 15:50:34 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "array_42.h"

void	*array_nfind(t_array set, size_t n,
		int (match)(const void *elem, const void *param), const void *param)
{
	void	*elem;

	while ((elem = array_get_at(&set, n++)) != NULL)
		if (match(elem, param))
			return (elem);
	return (NULL);
}
