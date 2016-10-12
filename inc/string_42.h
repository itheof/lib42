/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_42.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:28:48 by djean             #+#    #+#             */
/*   Updated: 2016/10/12 01:58:32 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_42_H
# define STRING_42_H

# include <stdlib.h>
# include "typedefs_42.h"
# include "structs_42.h"
# include "memory_42.h"
# include "stdlib_42.h"
# include "str_42.h"

# define STRING_INIT_SIZE		(64U)
# define STRING_GROWTH_FACTOR	(2U)

// TODO rename STRING_NEED_RESIZE
# define STRING_NEED_RESIZE(s, l) (s->len + l >= s->capacity)

// TODO delete iterator
# define TBUFFER_ITER(b)		((b)->iterator)
# define TBUFFER_RESET_ITER(b)	((b)->iterator = 0)

// TODO move definition in header file
// TODO rename file string_init.c
t_string	*string_init(t_string *s, size_t size);
void		string_destroy(t_string *s);

t_string	*string_dup(t_string *s, const char *str);
t_string	*string_ndup(t_string *s, const char *str, size_t len);
t_string	*string_cdup(t_string *s, const char *str, int c);
t_string	*string_twin(t_string *dst, const t_string *src);

t_string	*string_cat(t_string *s, const char *str);
t_string	*string_ncat(t_string *s, const char *str, size_t len);

t_string	*string_replace(t_string *s, const char *str);
t_string	*string_nreplace(t_string *s, const char *str, size_t len);
t_string	*string_set(t_string *s, int c, size_t len);

t_string	*string_resize(t_string *s, size_t expand);

t_string	*string_insert(t_string *s, size_t pos, const char *str, size_t l);
t_string	*string_append(t_string *dst, const t_string *src);
t_string	*string_merge(t_string *dst, const t_string *a, const t_string *b);
size_t		string_remove(t_string *s, size_t pos, size_t size);

int			string_rewind(t_string *s, size_t n);
int			string_rewindchr(t_string *s, int c);

t_string	*string_stoa(t_string *s, long long value, unsigned base);
t_string	*string_utoa(t_string *s, unsigned long long value, unsigned base);

// TODO delete iterator
char		string_iterator(t_string *b);
void		string_iterator_prev(t_string *b);
void		string_iterator_next(t_string *b);
void		string_iterator_set(t_string *b, size_t index);

#endif
