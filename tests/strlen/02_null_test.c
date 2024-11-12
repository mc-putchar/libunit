#include <string.h>

int null_test(void)
{
	char const	*str;

	str = NULL;
	if (strlen(str) == 0)
		return (0);
	return (-1);
}
