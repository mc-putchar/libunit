#include <stdlib.h>

int	test_abort(void)
{
	abort();
	if (1)
		return (0);
	return (-1);
}
