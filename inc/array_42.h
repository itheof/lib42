/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_42.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:28:48 by djean             #+#    #+#             */
/*   Updated: 2016/10/15 20:00:07 by crenault         ###   ########.fr       */
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

/*
** `array_create` and `array_create_with_capacity` malloc a new `t_array`
** and a new 'internal buffer' with
** (default size) * elem_size or capacity *elem_size if specified.
**
** `array_destroy` free the `t_array*` and the 'internal buffer'.
*/
t_array		*array_create(size_t elem_size); // TODO
t_array		*array_create_with_capacity(size_t capacity, size_t elem_size); // TODO
void		array_destroy(t_array *a); // TODO

/*
** `array_init` and `array_init_with_capacity` initialize an already
** existing array 'a': malloc the 'internal buffer' with
** (default size) * elem_size or capacity * elem_size if specified.
**
** `array_shutdown` free the 'internal buffer'.
*/
t_array		*array_init(t_array *a, size_t elem_size); // TODO
t_array		*array_init_with_capacity(t_array *a, size_t capacity, size_t elem_size); // TODO
t_array		*array_shutdown(t_array *a); // TODO

/*
** `array_reserve` enlarge the capacity of the array if (len + additional)
** is bigger than actual capacity.
**
** `array_shrink_to_fit` reduce the capacity of the 'internal buffer' to
** be the closest to the array length.
**
** `array_truncate` truncates the array. It returns the new size of the array
** or -1 if the truncate is to large.
*/
t_array		*array_reserve(t_array *a, size_t additional); // TODO
t_array		*array_shrink_to_fit(t_array *a); // TODO
ssize_t		array_truncate(t_array *a, size_t n); // TODO

t_array		*array_copy(t_array *dst, const t_array *src); // TODO rename clone

/*
** `array_get_at` returns the pointer on the data at the specified index,
** NULL if the index is out of range.
**
** `array_set_at` copy the element 'e' in the array at the index specified,
** returns the pointer on the element in the array,
** NULL if the index is out of range.
**
** TODO
*/
void		*array_get_at(t_array *v, size_t i);
void		*array_set_at(t_array *v, size_t i, const void *e);
// TODO better with a search_func, rework this name/function
int			array_indexof(t_array *v, void *e);

/*
** TODO delete this ? speak about that
*/
void		*array_create_node(t_array *v); // TODO delete this

/*
** `array_insert_at` insert an element at the specified index,
** returns NULL if the index is out of bounds.
**
** `array_replace_at` replace the element at the given index and
** if old is not NULL, write the element inside it. Returns NULL if the index
** is out of bounds.
*/
t_array		*array_insert_at(t_array *v, size_t i, const void *e);
void		*array_replace_at(t_array *v, size_t i, const void *e, void *old);

/*
** `array_remove_at` removes the element at the given index, if 'removed'
** is not NULL, the old data is written inside it. Returns NULL if the index
** is out of bounds.
**
** `array_remove_elem` removes the first element that is equal to 'e'.
** Returns NULL if element is not found.
*/
void		*array_remove_at(t_array *v, size_t i, void *removed);
void		*array_remove_elem(t_array *v, void *e);

/*
** `array_push` insert an element at the end of the array.
**
** `array_pop` remove the last element of the array. if 'old'
** is not NULL, the old data is written inside it.
*/
t_array		*array_push(t_array *v, const void *e);
void		*array_pop(t_array *v, void *old); // TODO pop if len == 0 ?

#endif
