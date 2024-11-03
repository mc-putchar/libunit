int	test_illegal(void)
{
	__asm__("ud2");
	if (1)
		return (0);
	return (-1);
}
