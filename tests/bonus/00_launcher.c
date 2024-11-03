#include "libunit.h"

extern int	test_abort(void);
extern int	test_fpe(void);
extern int	test_piperr(void);
extern int	test_illegal(void);
extern int	expect_fail(void);
extern int	surprise(void);
extern int	timeout_test(void);

int	test_bonus_launcher(void)
{
	t_unit	*test_unit;
	int		error;

	test_unit = create_timed_test_unit("bonus", 1);
	if (!test_unit)
		return (-1);
	error = 0;
	error |= add_test_expect(test_unit, "Test SIGABRT", &test_abort, ERRABRT);
	error |= add_test_expect(test_unit, "Test SIGFPE", &test_fpe, ERRFPE);
	error |= add_test_expect(test_unit, "Test SIGPIPE", &test_piperr, ERRPIPE);
	error |= add_test_expect(test_unit, "Test SIGILL", &test_illegal, ERRILL);
	error |= add_test_expect(test_unit, "Test SIGILL", &test_illegal, ERRILL);
	error |= add_test_expect(test_unit, "Test Failed", &expect_fail, KO);
	error |= add_test_expect(test_unit, "Test Timeout", &timeout_test, TIMEOUT);
	error |= add_test_expect(test_unit, "Test Surprise", &surprise, KO);
	if (error)
		return (-1);
	return (launch_unit(&test_unit));
}
