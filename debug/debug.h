#ifndef DEBUG_H
# define DEBUG_H

#include <stdio.h>
#define DEBUG_ARRAY_PRINT_STR	(0)
#define DEBUG_ARRAY_PRINT_PTR	(1)

#define debug_array_print(a, p)										\
	do {															\
		printf("array->capacity: %zu\n", (a)->capacity);			\
		printf("array->len: %zu\n", (a)->len);						\
		if ((p) == DEBUG_ARRAY_PRINT_STR)							\
		{															\
			for (size_t i = 0; i < (a)->capacity; ++i)				\
			printf("a->data[%zu] => %s\n", i, array_get_at(a, i));	\
		}															\
		else if ((p) == (void(*)(void*))DEBUG_ARRAY_PRINT_PTR)		\
		{															\
			for (size_t i = 0; i < (a)->capacity; ++i)				\
			printf("a->data[%zu] => %p\n", i, array_get_at(a, i));	\
		}															\
		else														\
		{															\
			for (size_t i = 0; i < (a)->capacity; ++i)				\
			{														\
				printf("a->data[%zu] => ", i);						\
				(*(void(*)(void*))p)(array_get_at(a, i));			\
			}														\
		}															\
	} while (0);													\

#endif
