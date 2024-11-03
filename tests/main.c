#include "libunit.h"

int	test_dummy_launcher(void);
int	test_bonus_launcher(void);
int	test_strlen_launcher(void);

int	main(int ac, char **av)
{
	int	res;

	if (ac != 1)
		return ((void)av, 1);
	res = 0;
	res |= test_dummy_launcher();
	res |= test_bonus_launcher();
	res |= test_strlen_launcher();
	return (res);
}
