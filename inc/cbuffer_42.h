/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cbuffer_42.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:28:48 by djean             #+#    #+#             */
/*   Updated: 2016/10/08 18:33:25 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CBUFFER_42_H
# define CBUFFER_42_H

# include <stdlib.h>
# include "typedefs_42.h"

# define CBUFFER_GET(b, i) ((char*)(b)->data + ((b)->elem_size * (i)))
# define CBUFFER_MOVE_BACKWARD(l, n) ((n) ? (n) - 1 : (l) - 1)
# define CBUFFER_MOVE_FORWARD(l, n) ((n) >= l - 1 ? 0 : (n) + 1)

t_cbuffer	*cbuffer_new(size_t len, size_t elem_size,
							void (*delete_func)(void *));
t_cbuffer	*cbuffer_init(t_cbuffer *buffer, size_t len, size_t elem_size,
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
