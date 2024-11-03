#include "libunit.h"

extern int	basic_test(void);
extern int	null_test(void);
extern int	bigger_str_test(void);
extern int	failing_test(void);

int	test_strlen_launcher(void)
{
	t_unit	*test_unit;
	int		error;

	test_unit = create_test_unit("strlen");
	if (!test_unit)
		return (-1);
	error = 0;
	error |= add_test(test_unit, "Basic test", &basic_test);
	error |= add_test(test_unit, "NULL test", &null_test);
	error |= add_test(test_unit, "Bigger string test", &bigger_str_test);
	error |= add_test(test_unit, "Failing test", &failing_test);
	if (error)
		return (-1);
	return (launch_unit(&test_unit));
}
