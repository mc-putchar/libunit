#if defined(__GNUC__)
# if defined(__i386__)
	# define MISALIGN_MEM	"pushf\norl $0x40000,(%esp)\npopf"
# elif defined(__x86_64__)
	# define MISALIGN_MEM	"pushf\norl $0x40000,(%rsp)\npopf"
# endif
#endif

int	test_buserr(void)
{
	__asm__(MISALIGN_MEM);
	if (1)
		return (0);
	return (-1);
}
