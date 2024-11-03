int	test_fpe(void)
{
	int	null;

	null = 0;
	if (42 / null)
		return (0);
	return (-1);
}
