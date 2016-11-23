/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_42.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 10:20:34 by djean             #+#    #+#             */
/*   Updated: 2016/11/23 10:51:01 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_42_H
# define LIST_42_H

# include <unistd.h>
# include <stdlib.h>
# include "typedefs_42.h"
# include "structs_42.h"
# include "pool_42.h"

# define NODE_SIZE(elem_size)	(sizeof(void*) + (elem_size))

/*
** `list_create` malloc a new `t_list`
**
** `list_destroy` free the `t_list` and all internal nodes
*/
t_list	*list_create(size_t elem_size);
void	list_destroy(t_list *l);

/*
** `list_init` initialize an already existing `t_list`,
** and initialize a new pool
**
** `list_shutdown` free the internal pool, therefore all the nodes
*/
t_list	*list_init(t_list *l, size_t elem_size);
void	list_shutdown(t_list *l);

/*
** `list_clear` set the len of the list to 0 and free the pool
*/
void	list_clear(t_list *l);

/*
**
*/
void	*list_get_at(const t_list *l, size_t i);
void	*list_set_at(const t_list *l, size_t i, const void *e);
ssize_t	list_index_of(const t_list *l, const void *e);
void	*list_get_first(const t_list *l);
void	*list_get_last(const t_list *l);

/*
**
*/
t_list	*list_insert_at(t_list *l, size_t i, const void *e);
t_list	*list_replace_at(t_list *l, size_t i, const void *e, void *old);
void	*list_get_available(t_list *l);

/*
**
*/
t_list	*list_remove_at(t_list *l, size_t i, void *removed);
t_list	*list_remove_elem(t_list *l, const void *e);

/*
**
*/
t_list	*list_push(t_list *l, const void *e);
t_list	*list_pop(t_list *l, void *old);

/*
**
*/
t_list	*list_swap(t_list *l, size_t e1, size_t e2);

#endif
