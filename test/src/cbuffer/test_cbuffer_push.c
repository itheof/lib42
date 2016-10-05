#include "header.h"

static void	test_00_cbuffer_pushFrontInt(void)
{
	t_cbuffer	buffer;

	cbuffer_init(&buffer, 3, sizeof(int));

	// cbuffer

	VTS;
}

void	suite_cbuffer_push(void)
{
	test_00_cbuffer_pushFrontInt();

	VSS;
}
