/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_42.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:28:48 by djean             #+#    #+#             */
/*   Updated: 2016/10/15 19:38:17 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_42_H
# define ARRAY_42_H

# include <stdlib.h>
# include <stdint.h>
# include "typedefs_42.h"
# include "structs_42.h"
# include "memory_42.h"
# include "stdlib_42.h"
# include "str_42.h"

# define TARRAY_MIN_SIZE		8
# define TARRAY_GROWTH_FACTOR	2
# define TARRAY_NEED_RESIZE(v)	((v)->len + 1 > (v)->capacity) // TODO delete
# define TARRAY_GET(v, i)		((char*)(v)->data + ((v)->elem_size * (i))) // TODO delete
# define TARRAY_ADDR_MIN(v)		((v)->data) // TODO delete
# define TARRAY_ADDR_MAX(v)		((void*)TARRAY_GET(v, (v)->len)) // TODO delete
# define TARRAY_IN_RANGE(v, p)	((p) >= (v)->data && (p) < TARRAY_ADDR_MAX(v)) // TODO delete ??

t_array		*array_create(size_t elem_size); // TODO
t_array		*array_create_with_capacity(size_t capacity, size_t elem_size); // TODO
void		array_destroy(t_array *a); // TODO

t_array		*array_init(t_array *a, size_t elem_size); // TODO
t_array		*array_init_with_capacity(t_array *a, size_t capacity, size_t elem_size); // TODO
t_array		*array_shutdown(t_array *a); // TODO

t_array		*array_reserve(t_array *a, size_t additional); // TODO
t_array		*array_shrink_to_fit(t_array *a); // TODO
ssize_t		array_truncate(t_array *a, size_t n); // TODO

t_array		*array_copy(t_array *dst, const t_array *src);

void		*array_get_at(t_array *v, size_t i);
void		array_set_at(t_array *v, size_t i, const void *e);
// TODO better with a search_func, rework this name/function
int			array_indexof(t_array *v, void *e);

void		*array_create_node(t_array *v); // TODO delete this

t_array		*array_insert_at(t_array *v, size_t i, const void *e);
void		*array_replace_at(t_array *v, size_t i, const void *e, void *old);

void		*array_remove_at(t_array *v, size_t i, void *removed);
void		*array_remove_elem(t_array *v, void *e);

t_array		*array_push(t_array *v, const void *e);
void		*array_pop(t_array *v, void *old);

#endif
