#include "ft_printf.h"

int	ft_printf_null_test(void)
{
	if (ft_printf(0))
		return (0);
	return (-1);
}
