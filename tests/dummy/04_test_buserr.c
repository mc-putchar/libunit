#include <stdlib.h>

#if defined(__GNUC__)
# if defined(__i386__)
	# define ENABLE_MEMALIGN	"pushf\norl $0x40000,(%esp)\npopf"
# elif defined(__x86_64__)
	# define ENABLE_MEMALIGN	"pushf\norl $0x40000,(%rsp)\npopf"
# endif
#endif

int	test_buserr(void)
{
	char	*p;
	int		*i;

	__asm__(ENABLE_MEMALIGN);
	p = malloc(sizeof(int) + 1);
	i = (int *)(++p);
	*i = 0;
	if (*p)
		return (0);
	return (-1);
}
