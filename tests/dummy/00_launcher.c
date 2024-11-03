#include "libunit.h"

extern int	test_ok(void);
extern int	test_ko(void);
extern int	test_segv(void);
extern int	test_buserr(void);

int	test_dummy_launcher(void)
{
	t_unit	*test_unit;
	int		error;

	test_unit = create_test_unit("dummy");
	if (!test_unit)
		return (-1);
	error = 0;
	error |= add_test(test_unit, "Test OK", &test_ok);
	error |= add_test(test_unit, "Test KO", &test_ko);
	error |= add_test(test_unit, "Test SIGSEGV", &test_segv);
	error |= add_test(test_unit, "Test SIGBUS", &test_buserr);
	if (error)
		return (-1);
	return (launch_unit(&test_unit));
}
