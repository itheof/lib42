/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_42.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:28:48 by djean             #+#    #+#             */
/*   Updated: 2016/10/15 14:57:02 by crenault         ###   ########.fr       */
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

// TODO move definitions in header file
t_string	*string_create(void);
t_string	*string_create_with_capacity(size_t capacity);
void		string_destroy(t_string *s);

t_string	*string_init(t_string *s);
t_string	*string_init_with_capacity(t_string *s, size_t capacity);
void		string_shutdown(t_string *s);

t_string	*string_dup(t_string *s, const char *str);
t_string	*string_ndup(t_string *s, const char *str, size_t len);
t_string	*string_clone(t_string *dst, const t_string *src);

t_string	*string_cat(t_string *s, const char *str);
t_string	*string_ncat(t_string *s, const char *str, size_t len);

t_string	*string_replace(t_string *s, const char *str);
t_string	*string_nreplace(t_string *s, const char *str, size_t len);
t_string	*string_set(t_string *s, int c, size_t len);

t_string	*string_insert(t_string *s, size_t pos, const char *str, size_t l);
t_string	*string_append(t_string *dst, const t_string *src);
t_string	*string_merge(t_string *dst, const t_string *a, const t_string *b);
size_t		string_remove(t_string *s, size_t pos, size_t size);

t_string	*string_reserve(t_string *s, size_t additional);

ssize_t		string_truncate(t_string *s, size_t n);
ssize_t		string_remove_back(t_string *s, size_t n);
ssize_t		string_remove_back_chr(t_string *s, int c);

t_string	*string_stoa(t_string *s, long long value, unsigned base);
t_string	*string_utoa(t_string *s, unsigned long long value, unsigned base);

#endif
