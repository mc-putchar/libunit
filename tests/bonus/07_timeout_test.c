int	timeout_test(void)
{
	int	idx;
	int	waste;

	idx = 1;
	while (idx < 1234567890 && ++idx)
	{
		waste = ((idx * idx) / (idx * 42)) % 123456;
		if (idx > 12345)
			idx = (idx * idx) % 42;
	}
	if (idx)
		return (0);
	return (-1);
}
