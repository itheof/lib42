/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_42.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:28:48 by djean             #+#    #+#             */
/*   Updated: 2016/10/11 02:12:41 by crenault         ###   ########.fr       */
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

# define STRING_INIT_SIZE		64U
# define STRING_GROWTH_FACTOR	2U
# define BUF_NEED_RESIZE(b, l)	(b->len + l >= b->sizemax)
# define TBUFFER_MAX(b)			((b)->sizemax)
# define TBUFFER_LEN(b)			((b)->len)
# define TBUFFER_GET(b)			((b)->str)
# define TBUFFER_FREE(b)		(free((b)->str))
# define TBUFFER_RESET(b)		((b)->str[(b)->len = 0] = '\0')
# define TBUFFER_LAST(b)		((b)->str[(b)->len - 1])
# define TBUFFER_FIRST(b)		((b)->str[0])
# define TBUFFER_ISEMPTY(b)		(!((b)->len))

// TODO delete iterator
# define TBUFFER_ITER(b)		((b)->iterator)
# define TBUFFER_RESET_ITER(b)	((b)->iterator = 0)

t_string	*string_new(size_t size);
t_string	*string_init(t_string *b, size_t size);
void		string_destroy(t_string *b);

t_string	*string_dup(const char *str);
t_string	*string_ndup(const char *str, size_t len);
t_string	*string_cdup(const char *str, int c);
t_string	*string_twin(t_string *b);

t_string	*string_cat(t_string *b, const char *s);
t_string	*string_ncat(t_string *b, const char *s, size_t len);

t_string	*string_replace(t_string *b, const char *s);
t_string	*string_nreplace(t_string *b, const char *s, size_t len);
t_string	*string_set(t_string *b, int c, size_t len);

t_string	*string_resize(t_string *b, size_t expand);

t_string	*string_insert(t_string *b, size_t pos, const char *s, size_t len);
t_string	*string_append(t_string *dst, t_string *src);
t_string	*string_merge(t_string *b1, t_string *b2);
size_t		string_remove(t_string *b, size_t pos, size_t size);

int			string_rewind(t_string *b, size_t n);
int			string_rewindchr(t_string *b, int c);

t_string	*string_stoa(t_string *b, long long value, unsigned base);
t_string	*string_utoa(t_string *b, unsigned long long value, unsigned base);

// TODO delete iterator
char		string_iterator(t_string *b);
void		string_iterator_prev(t_string *b);
void		string_iterator_next(t_string *b);
void		string_iterator_set(t_string *b, size_t index);

#endif
