/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cbuffer_42.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:28:48 by djean             #+#    #+#             */
/*   Updated: 2016/10/05 18:18:10 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CBUFFER_42_H
# define CBUFFER_42_H

# include <stdlib.h>
# include "typedefs_42.h"

# define CBUFFER_GET(v, i) ((char*)(v)->data + ((v)->elem_size * (i)))

t_cbuffer	*cbuffer_new(size_t len, size_t elem_size);
void		*cbuffer_init(t_cbuffer *buffer, size_t len, size_t elem_size);

void		cbuffer_push_back(t_cbuffer *buffer, void const *e);
void		cbuffer_push_front(t_cbuffer *buffer, void const *e);

void		cbuffer_index_push_back(size_t m, size_t *l, size_t *s, size_t *e);
void		cbuffer_index_push_front(size_t m, size_t *l, size_t *s, size_t *e);

// void		*array_resize(t_array *v);
// void		*array_get(t_array *v, size_t i);
// void		array_set(t_array *v, size_t i, void *e);
// int			array_indexof(t_array *v, void *e);
// void		*array_create_node(t_array *v);
// t_array		*array_add(t_array *v, void *e);
// void		*array_replace(t_array *v, size_t i, void *e, void *old);
// t_array		*array_insert(t_array *v, size_t i, void *e);
// void		*array_remove(t_array *v, size_t i, void *removed);
// void		*array_remove_elem(t_array *v, void *e);
// void		array_delete(t_array *v, size_t i);
// void		array_destroy(t_array *v);
// void		array_reset(t_array *v);
// t_array		*array_copy(t_array *v);
// t_array		*array_strsplit(char *str, char c);
// void		*array_iterator(t_array *v);
// void		array_iterator_prev(t_array *v);
// void		array_iterator_next(t_array *v);
// void		array_iterator_set(t_array *v, size_t index);

#endif
