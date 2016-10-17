/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:31:25 by djean             #+#    #+#             */
/*   Updated: 2016/10/17 12:06:33 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"

t_array			*array_create(size_t elem_size)
{
	t_array		*a;

	a = malloc(sizeof(t_array));
	if (a == NULL)
		return (NULL);
	if (array_init(a, elem_size) == NULL)
	{
		free(a);
		return (NULL);
	}
	return (a);
}

t_array			*array_create_with_capacity(size_t elem_size, size_t capacity)
{
	t_array		*a;

	a = malloc(sizeof(t_array));
	if (a == NULL)
		return (NULL);
	if (array_init_with_capacity(a, elem_size, capacity) == NULL)
	{
		free(a);
		return (NULL);
	}
	return (a);
}

void			array_destroy(t_array *a)
{
	free(a->data);
	free(a);
}
