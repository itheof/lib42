#include "header.h"

int	main(void)
{
	// memory
	suite_memset();
	suite_memcmp();
	suite_memcpy();
	suite_memccpy();
	suite_memchr();
	suite_memmove();

	// ctype
	suite_ctype();

	// stdlib
	suite_realloc();
	suite_toa_base();
	suite_next_power_of_2();

	// string
	suite_strlen();
	suite_strnlen();
	suite_strdup();
	suite_strndup();
	suite_strchr();
	suite_strrchr();
	suite_strrev();

	// buffer
	suite_buffer_dup();
	suite_buffer_cat();
	suite_buffer_insert();
	suite_buffer_append();
	suite_buffer_macros();
	suite_buffer_replace();
	suite_buffer_new();
	suite_buffer_resize();
	suite_buffer_remove();
	suite_buffer_set();
	suite_buffer_rewind();
	suite_buffer_rewindchr();
	/* suite_buffer_rewindnchr(); */
	suite_buffer_twin();
	suite_buffer_merge();
	suite_buffer_iterator();

	// array
	suite_array_macros();
	suite_array_indexof();
	suite_array_create_node();
	suite_array_push();
	suite_array_replace();
	suite_array_insert();
	suite_array_remove();
	/* suite_array_copy(); */
	suite_array_getset();
	suite_array_strsplit();
	suite_array_iterator();

	// error
	suite_error();

	// pool
	suite_pool_macros();
	suite_pool_new();
	suite_pool_obtain();
	suite_pool_return();
	suite_pool_reset();

	v_full_success("Lib42");
	return (0);
}
