/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cbuffer_42.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:28:48 by djean             #+#    #+#             */
/*   Updated: 2016/10/06 16:04:21 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CBUFFER_42_H
# define CBUFFER_42_H

# include <stdlib.h>
# include "typedefs_42.h"

# define CBUFFER_GET(b, i) ((char*)(b)->data + ((b)->elem_size * (i)))

t_cbuffer	*cbuffer_new(size_t len, size_t elem_size,
							void (*delete_func)(void *));
void		*cbuffer_init(t_cbuffer *buffer, size_t len, size_t elem_size,
							void (*delete_func)(void *));

t_cbuffer	*cbuffer_resize(t_cbuffer *buffer, size_t len);

void		cbuffer_push_back(t_cbuffer *buffer, void const *elem);
void		cbuffer_push_front(t_cbuffer *buffer, void const *elem);

void		*cbuffer_pop_back(t_cbuffer *buffer);
void		*cbuffer_pop_front(t_cbuffer *buffer);

void		*cbuffer_get(t_cbuffer *buffer, size_t i);
void		*cbuffer_get_front(t_cbuffer *buffer);
void		*cbuffer_get_back(t_cbuffer *buffer);

#endif
