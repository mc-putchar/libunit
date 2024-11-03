#include <string.h>

#define FT	"ft_wtf"
#define LEN	42

int	failing_test(void)
{
	if (strlen(FT) == LEN)
		return (0);
	return (-1);
}
