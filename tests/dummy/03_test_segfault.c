int	test_segv(void)
{
	int	*bad;

	bad = (int *)0xBADA55;
	if (bad[42] == 0x2A)
		return (0);
	return (-1);
}
