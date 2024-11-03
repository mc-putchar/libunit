#include <unistd.h>

int	test_piperr(void)
{
	int	fds[2];

	if (pipe(fds))
		return (-1);
	close(fds[0]);
	write(fds[1], "p", 1);
	if (1)
		return (0);
	return (-1);
}
