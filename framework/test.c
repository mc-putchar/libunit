/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 00:55:36 by mcutura           #+#    #+#             */
/*   Updated: 2024/11/03 23:17:51 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ansi_colors.h"
#include "libft.h"
#include "libunit.h"

void	output_prerun(char const *func_name, t_test *test)
{
	if (COLOR_PRINT)
	{
		(void)ft_printf("%s%s%s:%s %s: ", \
			WHTB, BBLK, func_name, CLR, test->name);
	}
	else
		(void)ft_printf("%s: %s: \n", func_name, test->name);
}

int	exec_test(t_test *test, unsigned int timeout, int log)
{
	pid_t	child;
	int		status;
	int		pfd[2];

	if (pipe(pfd))
		return (throw_error(-1, "Error: pipe error."));
	child = fork();
	if (child < 0)
		return (close(pfd[0]), close(pfd[1]), \
		throw_error(-1, "Error: fork it error."));
	else if (!child)
	{
		close(pfd[0]);
		dup2(pfd[1], STDOUT_FILENO);
		(void)alarm(timeout);
		status = test->func();
		exit(status);
	}
	close(pfd[1]);
	handle_log(log, pfd[0], NULL);
	return (pfd[0]);
}

void	output_result(t_test *test)
{
	if (COLOR_PRINT)
	{
		if (test->status == test->expect)
			(void)ft_printf("%s", GRN);
		else
			(void)ft_printf("%s", RED);
		(void)ft_printf("[%s]%s\n", g_status_name[test->status], CLR);
	}
	else
		(void)ft_printf("[%s]\n", g_status_name[test->status]);
}
