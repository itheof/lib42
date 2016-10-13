#ifndef TEST_LIB42_H
#define TEST_LIB42_H

#define _XOPEN_SOURCE 700
#define _DEFAUTL_SOURCE

#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#if !defined(__APPLE__)
#include <bsd/string.h>
#endif
#include <stdint.h>
#include <stdio.h>
#include "lib42.h"
#include "vittf.h"

// Array
void	suite_array_at(void);
void	suite_array_indexof(void);
void	suite_array_create_node(void);
void	suite_array_push(void);
void	suite_array_replace(void);
void	suite_array_insert(void);
void	suite_array_remove(void);
/* void	suite_array_copy(void); */

// Cbuffer
void	suite_cbuffer_push(void);
void	suite_cbuffer_pop(void);
void	suite_cbuffer_resize(void);

// String
void	suite_string_macros(void);
void	suite_string_new(void);
void	suite_string_resize(void);
void	suite_string_dup(void);
void	suite_string_cat(void);
void	suite_string_insert(void);
void	suite_string_remove(void);
void	suite_string_set(void);
void	suite_string_truncate(void);
void	suite_string_truncate_chr(void);
/* void	suite_string_rewindnchr(void); */
void	suite_string_append(void);
void	suite_string_replace(void);
void	suite_string_clone(void);
void	suite_string_merge(void);
void	suite_string_iterator(void);

// Memory
void	suite_memcpy(void);
void	suite_memccpy(void);
void	suite_memcmp(void);
void	suite_memmove(void);
void	suite_memset(void);
void	suite_memchr(void);

// Stdlib
void	suite_realloc(void);
void	suite_toa_base(void);
void	suite_next_power_of_2(void);

// Ctype
void	suite_ctype(void);

// Str
void	suite_strcmp(void);
void	suite_strlen(void);
void	suite_strnlen(void);
void	suite_strdup(void);
void	suite_strndup(void);
void	suite_strchr(void);
void	suite_strrchr(void);
void	suite_strrev(void);
void	suite_strstr(void);
void	suite_strrstr(void);

// Pool
void	suite_pool_macros(void);
void	suite_pool_new(void);
void	suite_pool_obtain(void);
void	suite_pool_return(void);
void	suite_pool_reset(void);

// Error
void	suite_error(void);

// unistd

void	suite_unistd_getopt(void);

#endif
