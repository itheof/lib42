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

	// str
	suite_strcmp();
	suite_strlen();
	suite_strnlen();
	suite_strdup();
	suite_strndup();
	suite_strchr();
	suite_strrchr();
	suite_strrev();
	suite_strstr();
	suite_strrstr();

	// string
	suite_string_dup();
	suite_string_cat();
	suite_string_reserve();
	suite_string_shrink_to_fit();
	suite_string_insert();
	suite_string_append();
	suite_string_replace();
	suite_string_create_init();
	suite_string_remove();
	suite_string_set();
	suite_string_truncate();
	suite_string_remove_back();
	suite_string_remove_back_chr();
	/* suite_string_rewindnchr(); */
	suite_string_clone();
	suite_string_merge();

	// array
	suite_array_indexof();
	suite_array_create_node();
	suite_array_push();
	suite_array_replace();
	suite_array_insert();
	suite_array_remove();
	/* suite_array_copy(); */
	suite_array_at();

	// cbuffer
	suite_cbuffer_push();
	suite_cbuffer_pop();
	suite_cbuffer_resize();

	// error
	suite_error();

	// pool
	suite_pool_macros();
	suite_pool_new();
	suite_pool_obtain();
	suite_pool_return();
	suite_pool_reset();

	suite_unistd_getopt();

	v_full_success("Lib42");
	return (0);
}
