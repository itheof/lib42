/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:14:53 by djean             #+#    #+#             */
/*   Updated: 2016/05/18 19:05:13 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_42.h"

void	*ft_vector_get(t_vector *v, size_t i)
{
	if (i >= v->total)
		return (NULL);
	return (v->data[i]);
}
